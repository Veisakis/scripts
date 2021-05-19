#!/bin/bash

used=$(df -h | grep /dev/sda5 | cut -d' ' -f10)
total=$(df -h | grep /dev/sda5 | cut -d' ' -f8)

echo "$used / $total"
