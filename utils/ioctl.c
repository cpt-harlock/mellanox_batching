#include "../mlx5/core/en_ioctl.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_FILE "/sys/kernel/debug/mlx5/0000:34:00.1/cmd/run" // Replace with your device file

int main(int argc, char* argv[]) {
	int fd;
	char *data = "Hello, World!";

	if (argc < 2) {
		printf("Error, usage: sudo ./ioctl <cmd_number>\n");
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
	} else {
		if (ioctl(fd, SET_METADATA) < 0) {
			perror("Failed to write data using ioctl");
			close(fd);
			return -1;
		}
	}
	// Close the device file
	close(fd);
	return 0;
}

