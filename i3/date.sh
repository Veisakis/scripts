#!/bin/bash

#bd_file=~/myfiles/birthdays
#today=$(date '+%d/%m')
date=$(date '+%d/%m/%y %H:%M:%S')
echo $date

# Search for a match, only if birthday file exists
#if [ -s $bd_file ]; then
#	result=$(awk -v today=$today '{if ($2 == today) print 1; else 0}' < $bd_file)
#else
#	result=0
#fi
#
#if [ $result ]; then
#	echo 🎆 $date 
#else
#	echo 📅 $date
#fi
#
#case $BLOCK_BUTTON in
#	1) notify-send -i "/home/manousos/myfiles/icons/calendar.png" -u low "$(cal -3)"
#esac
