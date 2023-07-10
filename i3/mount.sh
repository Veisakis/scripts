#!/bin/bash

options=$(lsblk -pl | awk '/part $/ {print $1, "("$4")"}' | dmenu -p  )
device=$(echo $options | awk '{print $1}')

sudo mount $device ~/myfiles/mnt -o uid=1000,gid=998,umask=0022

