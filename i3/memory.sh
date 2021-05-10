#!/bin/bash

usedmem=$(free -h | awk "NR==2" | cut -d' ' -f18)
totalmem=$(free -h | awk "NR==2" | cut -d' ' -f11)

echo "RAM: $usedmem / $totalmem"
