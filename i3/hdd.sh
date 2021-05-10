#!/bin/bash

used=$(df -h | grep /dev/sdb2 | cut -d' ' -f11)
total=$(df -h | grep /dev/sdb2 | cut -d' ' -f8)

echo "$used / $total"
