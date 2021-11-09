#!/bin/bash

status=$(amixer get Master | awk 'NR==5 {print $6}' | grep -o '[a-z]*')

if [[ $status = on ]]
then
	echo "🔊 $(amixer get Master | grep -o '[0-9]*%')"
else
	echo "🔇 $(amixer get Master | grep -o '[0-9]*%')"
fi
