# SPDX-License-Identifier: GPL-2.0-only
#
# Makefile for the Mellanox device drivers.
#

.PHONY: all

all:
	@echo "Building Mellanox device drivers..."
	$(MAKE) -C  ./mlx5/core
