# Use batched mlx5 driver

This Mellanox 5 driver support batched packets processing.   
It is based on the original mlx5 driver.   

The batched packets processing is `disabled` by default. The batched packets processing can be toogled by userspace.   

## Build drivers

```bash
cd mlx5/core
make
```

## Load drivers

```bash
rmmod mlx5_ib
rmmod mlx5_core
ip link set <ifname> down
insmod mlx5_core.ko
ip link set <ifname> up
ethtool --set-priv-flags <ifname> rx_striding_rq off
ethtool --set-rxfh-indir <ifname> equal 1
ethtool --set-priv-flags <ifname> xdp_tx_mpwqe off
ip link set <ifname> promisc on
```

## Toogle batched packets processing and other driver interactions

In order to toggle the batched packets processing, the user can use the `ioctl` utility in the `mellanox_batching/utils` directory.
```bash
./mellanox_batching/utils/ioctl 0 # disable batching processing
./mellanox_batching/utils/ioctl 1 # enable batching processing
```

The user can also read incoming rx packets using:
```bash
./mellanox_batching/utils/ioctl 3 # read rx packets
```

# How a batched packet is builded
A batched packet is essentially a list of packets, where each packet contain the next packet in the payload.

Here is an example of a two-batched packet and a four-batched packet:
```
+---------------------+                 +---------------------+
|   Batched Header    |                 |   Batched Header    |
+---------------------+                 +---------------------+
|      Ethernet       |                 |      Packet 1       |
+---------------------+                 +---------------------+
|         IP          |                 |   Batched Header    |
+---------------------+                 +---------------------+
|         ⋮          |                 |      Packet 2       |
+---------------------+                 +---------------------+
|    Next Packet      |                 |   Batched Header    |
+---------------------+                 +---------------------+
                                        |      Packet 3       |
                                        +---------------------+
                                        |      Packet 4       |
                                        +---------------------+
                                        
```
The batched header is a 16 bytes header that contains the metadata of the batched packet.

| Batch Header    |                         |
|-----------------|----------------------   |
| bitmap [15:12]  |  next packet len [11:0] |

The **bitmap** field tells the NIC's driver which packets in the batch are to be processed. 

# Batching in XDP

The goal of batching in XDP is to process multiple packets in a single iteration.

## How to program a batched XDP application

With the batched mlx5 driver, XDP see the batched packet as a single packet.  

In order to access to the next packet in a batched XDP program it is just necessary to read `ctx->data` shifted by `next_packet_len`.

The `next_packet_len` is stored in `ctx->metadata`.

It's simpler to understand with an example, where we want to do some processing on both the first and the second packet and then pass the first one and drop the second one.
```c
int xdp_func(struct xdp_md *ctx) {
    void *data_end = (void *)(long)ctx->data_end;
    void *data = (void *)(long)ctx->data;

    void *metadata = ctx->metadata;

    // parse the buffer pointed by metadata
    struct metadata_t *md = metadata;
    if (md + 1 > data)
    {
        return XDP_DROP + (XDP_DROP << 4);
    }
    
    // get the packet len until the next packet
    __u8 offset = bpf_ntohs(md->offset) & 0xFF;

    struct ethhdr *eth1 = data;
    if (eth + 1 > data_end || eth + 1 > data + offset) {...}
    .
    .
    .
    
    struct ethhdr *eth2 = data +  (bpf_ntohs(md->offset) & 0xFF);
    if (eth2 + 1 > data_end) {...}

    return XDP_PASS + (XDP_TX << 4);
}
```

Examples of batching application can be found on [this repo](https://github.com/CiZ01/bxdp.git).
