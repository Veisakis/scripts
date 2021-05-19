#!/bin/bash

status=$(cat /sys/class/power_supply/BAT0/capacity)

if [ $(cat /sys/class/power_supply/AC/online) -eq 0 ]
then
	if [ $status -lt 20 ]
	then
		echo 🔋$status%
		echo "" 
		echo "#FF001D"
		echo ""
	else
		echo 🔋$status%
	fi
else
	echo ⚡$status%
fi
