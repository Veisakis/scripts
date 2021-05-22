#!/bin/bash
#Run as superuser (sudo su)

sudo apt update
sudo apt install apt-transport-https curl

sudo curl -fsSLo /usr/share/keyrings/brave-browser-archive-keyring.gpg https://brave-browser-apt-release.s3.brave.com/brave-browser-archive-keyring.gpg

echo "deb [signed-by=/usr/share/keyrings/brave-browser-archive-keyring.gpg arch=amd64] https://brave-browser-apt-release.s3.brave.com/ stable main"|sudo tee /etc/apt/sources.list.d/brave-browser-release.list

sudo apt update
sudo apt install vim git sxiv zathura mpv python3 python3-pip brave-browser nmap hydra texlive-full i3 i3blocks

pip install matplotlib pandas virtualenv

#cd && rm -rf Movies Music Videos Pictures Documents 2>/dev/null && mkdir -p .ssh scripts Wallpapers Documents

#Git
#cd ~/Desktop && git clone git@github.com:/Veisakis/config && git clone git@github.com:/Veisakis/scripts
#cp ~/Desktop/scripts/bandwidth.sh ~/scripts/ && cp -r ~/Desktop/scripts/i3 ~/scripts/
#cp ~/Desktop/config/linux/.bashrc ~ && cp ~/Desktop/config/linux/.vimrc ~ && cp ~/Desktop/config/linux/i3/config ~/.config/i3/ && cp ~/Desktop/config/linux/i3/i3blocks.conf /etc
#cd ~/Desktop && rm -rf *
#Git
