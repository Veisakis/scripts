#!/bin/bash

if [ ! -s $1 ]
then
	echo "File '$1' could not be found."
	exit 0
fi

while read film; do
	transmission-remote -a $film
done <$1
