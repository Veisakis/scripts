#!/bin/bash

options=$(lsblk -pl | grep "part $" | awk '{print $1, "("$4")"}' | dmenu)

device=$(echo $options | awk '{print $1}')

sudo mount $device /mnt

