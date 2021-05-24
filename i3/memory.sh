#!/bin/bash

usedmem=$(free -h | awk 'NR==2 {print $3}' )
totalmem=$(free -h | awk 'NR==2 {print $2}')

echo "RAM: $usedmem / $totalmem"
