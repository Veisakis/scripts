#!/bin/bash

used=$(df -h | grep /dev/sda5 | cut -d' ' -f12)
total=$(df -h | grep /dev/sda5 | cut -d' ' -f9)

echo "$used / $total"
