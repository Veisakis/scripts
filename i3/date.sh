#!/bin/bash

bd_file=~/myfiles/birthdays
today=$(date '+%d/%m')
date=$(date '+%d/%m/%y %H:%M:%S')

# Search for a match, only if birthday file exists
if [ -s $bd_file ]; then
	result=$(awk -v today=$today '{if ($2 == today) print 1; else 0}' < $bd_file)
else
	result=0
fi

if [ $result ]; then
	echo $date
	echo
	echo "#000000"
	echo "#99ccff"
else
	echo $date
fi

