#!/bin/bash

up=$(transmission-remote -l | grep Sum | awk '{print $4}')
down=$(transmission-remote -l | grep Sum | awk '{print $5}')

echo "$down kB/sec"

