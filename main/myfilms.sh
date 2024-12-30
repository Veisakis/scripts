#!/bin/bash

path="/media/Archive"
count=$(ls $path | wc -l)
size=$(df -h | awk '/Archive/ {print $4"/"$2}')

ls $path --sort=time | head -n15

echo -e "\nTotal films: $count"
echo -e "Available Space: $size"
