#!/bin/bash

freq=$(cat /proc/cpuinfo | awk '/cpu MHz/ {print $4; exit}' | cut -d. -f1)

#echo $freq MHz
printf "%.4d Hz\n" $freq
