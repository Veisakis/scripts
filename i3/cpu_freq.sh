#!/bin/bash

freq=$(cat /proc/cpuinfo | grep "cpu MHz" | awk 'NR==1 {print $4}')

echo $freq MHz
