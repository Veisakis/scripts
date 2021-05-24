#!/bin/bash

echo $(sensors | grep temp1 | awk 'NR==1 {print $2}')
