#!/bin/bash

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

for cli in python imagemagick youtube-dl tldr; do
	brew install &cli
done

for app in evernote dropbox sublime-text firefox vlc; do
	brew cask install $app
done


