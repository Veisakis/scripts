#!/bin/bash

temp=$(sensors | awk "NR==9" | grep -o [0-9][0-9] | awk "NR==1")

echo "$temp°C"
