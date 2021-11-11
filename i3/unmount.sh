#!/bin/bash

options=$(lsblk -pl | grep "part /mnt" | awk '{print $1, "("$4")"}' | dmenu -p  )

device=$(echo $options | awk '{print $1}')

sudo umount $device
