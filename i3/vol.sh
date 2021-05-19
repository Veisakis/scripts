#!/bin/bash

echo 🔊 $(amixer get Master | grep -o "[0-9]*%")
