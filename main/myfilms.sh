#!/bin/bash

path="/home/manousos/myfiles/movies"
count=$(ls $path | wc -l)

ls $path --sort=time | head -n15
echo -e "\nTotal films: $count"
