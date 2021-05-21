#!/bin/bash

echo "$(curl -s wttr.in/Chania?TA | awk 'NR==4' | grep -oE '[\+\-]?[0-9][0-9]?' | awk 'NR==1' | sed 's/$/\°C/')"
