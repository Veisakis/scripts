#!/bin/bash

echo url="https://www.duckdns.org/update?domains=istoria&token=9831b330-404b-4b64-aff1-da3ae8ea517f&ip=" | curl -k -o /home/pi/duckdns/duck.log -K -
