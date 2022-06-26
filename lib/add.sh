#!/bin/sh

ls *.c | xargs gcc -c
ar cr libcustom.a *.o
rm *.o
