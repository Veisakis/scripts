#!/bin/bash

down=$(transmission-remote -l | awk '/Sum/{print $5}')

echo "$down kB/sec"

