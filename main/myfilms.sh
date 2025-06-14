#!/bin/bash

path="/home/manousos/myfiles/movies"
count=$(ls $path | wc -l)
remain=$(lsblk -l -o +FSSIZE,FSUSED | awk '/movies/ {print $8-$9" GB"}')
size=$(df -h | awk '/movies/ {print $4"/"$2}')
size=$(df -h | awk '/Archive/ {print $4"/"$2}')

ls $path --sort=time | head -n15

echo -e "\nTotal films: $count"
echo "Remaining Disk Capacity: $remain"
echo -e "Available Space: $size"
