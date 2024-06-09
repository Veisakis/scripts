#!/bin/bash

echo $(sensors | awk '/temp1/ {print $2}' | head -n1)
