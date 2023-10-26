#!/bin/bash

notify-send -t 3000 -u low -i ~/myfiles/icons/box.png "Transmission" "Download Completed!"

pkill -SIGRTMIN+7 i3blocks
