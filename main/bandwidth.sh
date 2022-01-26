#!/bin/bash

start=$(cat /proc/net/dev | awk "NR==4" | cut -d' ' -f2)
echo "Started monitoring..."

read
end=$(cat /proc/net/dev | awk "NR==4" | cut -d' ' -f2)

echo $(( end - start )) bytes
