#!/bin/bash

case $BLOCK_BUTTON in
	1) gnome-terminal --window-with-profile=i3blocks -- curl wttr.in/Chania ;;
	*) echo "$(curl -s wttr.in/Chania?TA | awk 'NR==4' | grep -oE '[\+\-]?[0-9][0-9]?' | awk 'NR==1' | sed 's/$/\°C/')" ;;
esac
