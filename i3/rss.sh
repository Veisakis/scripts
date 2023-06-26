#!/bin/bash

news=$(newsboat -x reload print-unread | awk '{print $1}')

if [ $news -gt 0 ]
then
	echo 📬
else
	echo 📪
fi
