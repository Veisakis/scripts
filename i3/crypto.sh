#!/bin/bash

balance=0.01285497
price=$(curl -s rate.sx/btc | grep begin | awk '{print $2}' | tr -d '$')

result=$(bc <<< "scale=2; $balance * $price" | awk '{printf("%.2f\n", $1)}')
echo   $result
