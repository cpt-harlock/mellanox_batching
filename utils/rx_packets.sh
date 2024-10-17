#!/bin/bash

# Get the number of received packets using ioctl
old=$(sudo ./ioctl 2 | cut -d ' ' -f 2)
sleep 1
new=$(sudo ./ioctl 2 | cut -d ' ' -f 2)
echo $((new - old))

