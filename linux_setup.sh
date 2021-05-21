#!/bin/bash

sudo apt update
sudo apt install apt-transport-https curl

sudo curl -fsSLo /usr/share/keyrings/brave-browser-archive-keyring.gpg https://brave-browser-apt-release.s3.brave.com/brave-browser-archive-keyring.gpg

echo "deb [signed-by=/usr/share/keyrings/brave-browser-archive-keyring.gpg arch=amd64] https://brave-browser-apt-release.s3.brave.com/ stable main"|sudo tee /etc/apt/sources.list.d/brave-browser-release.list

sudo apt update
sudo apt install vim git sxiv zathura mpv python3 python3-pip brave-browser texlive-full i3 i3blocks hydra

pip install matplotlib pandas virtualenv

cd && mkdir -p .ssh scripts Documents/templates lists

cd ~/scripts && git clone https://github.com/Veisakis/scripts . && rm !(bandwidth.sh) 2>/dev/null

cd ~/Desktop && git clone https://github.com/Veisakis/config
cd config/linux && cp .bashrc ~ && cp .vimrc ~ && cp i3/config ~/.config/i3/ && cp i3/i3blocks.conf /etc/
cd ~/Desktop && rm -rf config
