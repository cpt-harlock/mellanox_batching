#include <linux/ioctl.h>

#define SET_METADATA _IO('mlx5_ioctl',0)
#define RESET_METADATA _IO('mlx5_ioctl',1)
#define READ_RX_PACKETS _IOR('mlx5_ioctl',2, uint64_t)
#define PREFETCH_ENABLE _IO('mlx5_ioctl',3)
#define PREFETCH_DISABLE _IO('mlx5_ioctl',4)
