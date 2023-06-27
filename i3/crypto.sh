#!/bin/bash

balance=0.01285497
threshold=400

price=$(curl -s rate.sx/${balance}BTC)
xrate=$(curl -s https://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml | awk -F'=' '/USD/ {print substr($3,2,6)}')

result_flt=$(bc <<< "scale=2; $price / $xrate")
result_int=$(echo $result_flt | awk '{printf "%d", $1}')

echo   $result_flt

if [ $result_int -gt $threshold ]
then
				echo
				echo "#66ff66"
fi
