#!/bin/bash

# Get the number of received packets using ioctl
old=$(sudo ./ioctl 2 )
sleep 1
new=$(sudo ./ioctl 2 )
printf "%'d\n" $((new - old))

