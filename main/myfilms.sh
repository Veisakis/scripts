#!/bin/bash

count=$(ls /media/Archive/MM | wc -l)

ls /media/Archive/MM --sort=time | head -n15
echo -e "\nTotal films: $count"
