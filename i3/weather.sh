#!/bin/bash

sleep 5

loss=$(ping -q -c1 wttr.in | awk 'NR==4 {print $6}' | grep -o [0-9]*)

if [ $loss -eq 0 ]
then
	echo "$(curl -s wttr.in/Chania?TA | awk 'NR==4' | grep -oE '[\+\-]?[0-9][0-9]?' | awk 'NR==1' | sed 's/$/\°C/')"
else
	echo "Connection Error"
fi
