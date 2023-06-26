#!/bin/bash

used=$(df -h | awk '/sdc3/{print $3}')
total=$(df -h | awk '/sdc3/{print $2}')

echo "$used 💾 $total"
