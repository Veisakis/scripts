#!/bin/bash

song=$(mpc -f %title% | head -n1)
clock=$(mpc | awk 'NR==2 {print $3}')

echo "$song [$clock]"
