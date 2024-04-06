#!/bin/bash

path="/media/Archive"
count=$(ls $path | wc -l)

ls $path --sort=time | head -n15
echo -e "\nTotal films: $count"
