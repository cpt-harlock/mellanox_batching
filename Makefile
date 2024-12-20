# SPDX-License-Identifier: GPL-2.0-only
#
# Makefile for the Mellanox device drivers.
#

.PHONY: all reload load

all:
	@echo "Building Mellanox device drivers..."
	$(MAKE) -C  ./mlx5/core

reload:
	@echo "Reloading Mellanox device drivers..."
	( cd ./mlx5/core; $(MAKE) reload )

load:
	@echo "Loading Mellanox device drivers..."
	sudo rmmod mlx5_ib
	( cd ./mlx5/core; $(MAKE) reload )
