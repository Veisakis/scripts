#!/bin/bash

options=$(lsblk -pl | awk '/part \/mnt/ {print $1, "("$4")"}' | dmenu -p  )
device=$(echo $options | awk '{print $1}')

sudo umount $device
