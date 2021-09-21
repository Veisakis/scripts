#!/bin/bash

lang=$(xkb-switch)

if [[ $lang = us ]]
then
	echo 🇺🇸
else
	echo 🇬🇷
fi
