#!/bin/bash

case $BLOCK_BUTTON in
	1) st -e newsboat ;;
esac
sleep 10 && newsboat -x print-unread | awk '{print $1}'