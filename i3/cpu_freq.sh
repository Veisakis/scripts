#!/bin/bash

freq=$(cat /proc/cpuinfo | awk '/cpu MHz/ {print $4; exit}')

echo $freq MHz
