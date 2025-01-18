#!/bin/bash

path="/home/manousos/myfiles/movies"
count=$(ls $path | wc -l)
<<<<<<< HEAD
remain=$(lsblk -l -o +FSSIZE,FSUSED | awk '/movies/ {print $8-$9" GB"}')
=======
size=$(df -h | awk '/Archive/ {print $4"/"$2}')
>>>>>>> c97bf1a27f60728676df3ad390cffc393a8000bc

ls $path --sort=time | head -n15

echo -e "\nTotal films: $count"
<<<<<<< HEAD
echo "Remaining Disk Capacity: $remain"
=======
echo -e "Available Space: $size"
>>>>>>> c97bf1a27f60728676df3ad390cffc393a8000bc
