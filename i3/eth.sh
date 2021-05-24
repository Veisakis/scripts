#!/bin/bash

sleep 5

case $BLOCK_BUTTON in
	1) echo "🌍 $(curl https://ipinfo.io/ip)" ;;
	*) echo "🏠 $(ifconfig | grep -o "192\S*\s")" ;;
esac
