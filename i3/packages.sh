#!/bin/bash

finished_packages=$(transmission-remote -l | awk '/100%/ {packages = packages + 1} END {print packages}')

echo $finished_packages📦
