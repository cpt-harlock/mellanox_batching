#include <linux/ioctl.h>

#define SET_METADATA _IO('mlx5_ioctl','set')
#define RESET_METADATA _IO('mlx5_ioctl','reset')
#define READ_RX_PACKETS _IOR('mlx5_ioctl','read_rx_packets', uint64_t)
