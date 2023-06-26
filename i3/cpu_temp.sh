#!/bin/bash

echo $(sensors | awk '/temp1/ {print $2}')
