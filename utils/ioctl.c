#include "../mlx5/core/en_ioctl.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)


#define DEVICE_FILE "/sys/kernel/debug/mlx5/0000:34:00.1/cmd/run" // Replace with your device file

int main(int argc, char* argv[]) {
	int fd;
	char *data = "Hello, World!";

	if (argc < 2) {
		printf("Error, usage: sudo ./ioctl <cmd_number> [cmd_args]\n");
		exit(-1);
	}

	int cmd = atoi(argv[1]);
	// Open the device file
	fd = open(DEVICE_FILE, O_RDWR);
	if (fd < 0) {
		perror("Failed to open device");
		return 1;
	}
	if (cmd == 0) {
		if (ioctl(fd, RESET_METADATA) < 0) {
			perror("Failed to write data using ioctl");
			close(fd);
			return -1;
		}
	} else if (cmd == 1) {
		if (ioctl(fd, SET_METADATA) < 0) {
			perror("Failed to write data using ioctl");
			close(fd);
			return -1;
		}
	} else if (cmd == 2) {
		uint64_t data = 0;
		if (ioctl(fd, READ_RX_PACKETS, &data) < 0) {
			perror("Failed to write data using ioctl");
			close(fd);
			return -1;
		}
		printf("%lu\n", data);
	} else if (cmd == 3) {
		// like cmd == 2, but do two readings with a delay in between of 1 second
		// get delay from args
		uint64_t delay = atol(argv[2]);
		uint64_t data_start = 0;
		uint64_t data_end = 0;
		if (unlikely(ioctl(fd, READ_RX_PACKETS, &data_start) < 0)) {
			perror("Failed to write data using ioctl");
			close(fd);
			return -1;
		}
		sleep(delay);
		if (unlikely(ioctl(fd, READ_RX_PACKETS, &data_end) < 0)) {
			perror("Failed to write data using ioctl");
			close(fd);
			return -1;
		}
		printf("%lu\n", data_end - data_start);
	}
	else {
		printf("Invalid command number\n");
		close(fd);
		return -1;
	}
	// Close the device file
	close(fd);
	return 0;
}

