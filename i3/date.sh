#!/bin/bash

today=$(date '+%d/%m')
date=$(date '+%d/%m/%y %H:%M:%S')

result=$(awk -v today=$today '{if ($2 == today) print 1; else 0}' < ~/myfiles/birthdays)

if [ $result ]; then
	echo $date
	echo
	echo "#ffffff"
	echo "#ef5350"
else
	echo $date
fi

