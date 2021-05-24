#!/bin/bash

cap=$(cat /sys/class/power_supply/BAT0/capacity)

if [ $(cat /sys/class/power_supply/AC/online) -eq 0 ]
then
	if [ $cap -lt 20 ]
	then
		echo 🔋$cap%
		echo "" 
		echo "" 
		echo "#FF001D"
	else
		echo 🔋$cap%
	fi
else
	if [ $cap -eq 100 ]
	then
		echo ⚡$cap%
	else	
		echo ⚡$cap%
	fi
fi
