#!/bin/bash

path="/home/manousos/myfiles/movies"
count=$(ls $path | wc -l)
remain=$(lsblk -l -o +FSSIZE,FSUSED | awk '/movies/ {print $8-$9" GB"}')
<<<<<<< HEAD
size=$(df -h | awk '/movies/ {print $4"/"$2}')
=======
size=$(df -h | awk '/Archive/ {print $4"/"$2}')
>>>>>>> fe5fc3b (Fixed myfilms.)

ls $path --sort=time | head -n15

echo -e "\nTotal films: $count"
<<<<<<< HEAD
=======
echo "Remaining Disk Capacity: $remain"
>>>>>>> fe5fc3b (Fixed myfilms.)
echo -e "Available Space: $size"
