#!/bin/bash

options=$(lsblk -pl | awk '/part $/ {print $1, "("$4")"}' | dmenu -p  )
device=$(echo $options | awk '{print $1}')

sudo mount $device /mnt

