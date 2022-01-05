#!/bin/bash

sleep 5

case $BLOCK_BUTTON in
	1) echo   $(curl -s rate.sx/btc | grep begin | awk '{print $2}') ;;
	*) echo   $(curl -s rate.sx/xmr | grep begin | awk '{print $2}') ;; 
esac
