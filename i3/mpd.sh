#!/bin/bash

song=$(mpc -f %title% | head -n1)
clock=$(mpc | sed -n 2p | awk '{print $3}')

echo "$song [$clock]"
