#include <linux/ioctl.h>

#define SET_METADATA _IOW('mlx5_ioctl','set',int32_t*)
#define RESET_METADATA _IOW('mlx5_ioctl','reset',int32_t*)
