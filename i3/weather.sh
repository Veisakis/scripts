#!/bin/bash

if [ $loss -eq 0 ]
then
	echo "$(curl -s wttr.in/Athens?format='%M%m-%c%t')"
else
	echo "Connection Error"
fi
