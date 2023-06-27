#!/bin/bash

balance=0.01285497
threshold=400

price=$(curl -s rate.sx/btc | awk '/begin/ {print $2}' | tr -d '$')

result_flt=$(bc <<< "scale=2; $balance * $price" | awk '{printf("%.2f\n", $1)}')
result_int=$(echo $result_flt | awk '{printf "%d", $1}')

echo   $result_flt

if [ $result_int -gt $threshold ]
then
				echo
				echo "#66ff66"
fi
