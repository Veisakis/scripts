#!/bin/bash

for url in cMvE64ZU7X4 r4S4z6BREeI i5zweihZCXg Q1skjZjHCbc dNFitxST5lY iqdL3qPDQ7s K9hw9VwvFB8 vlpaZDVEfhU a1auWS97QUI
do
	link=$"https://www.youtube.com/watch?v=$url"
	youtube-dl -x --audio-format mp3 $link
done
