#!/bin/bash

use=$(mpstat 1 | awk 'NR==4 {print $4; exit}')
echo "$use%"
