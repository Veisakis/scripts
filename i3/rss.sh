#!/bin/bash

sleep 5
news=$(newsboat -x reload print-unread | awk '{print $1}')

case $BLOCK_BUTTON in
	1) st -e newsboat ;;
esac

if [ $news -gt 0 ]
then
	echo 📬
else
	echo 📪
fi
