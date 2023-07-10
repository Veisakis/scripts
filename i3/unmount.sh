#!/bin/bash

options=$(lsblk -pl | awk '/part \/home\/manousos\/myfiles\/mnt/ {print $1, "("$4")"}' | dmenu -p  )
device=$(echo $options | awk '{print $1}')

sudo umount $device
