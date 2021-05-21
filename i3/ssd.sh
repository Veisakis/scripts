#!/bin/bash

used=$(df -h | grep /dev/sda5 | awk '{print $3}')
total=$(df -h | grep /dev/sda5 | awk '{print $2}')

echo "$used / $total"
