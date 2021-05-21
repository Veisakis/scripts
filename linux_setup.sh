#!/bin/bash
#Run as superuser (sudo su)

sudo apt update
sudo apt install apt-transport-https curl

sudo curl -fsSLo /usr/share/keyrings/brave-browser-archive-keyring.gpg https://brave-browser-apt-release.s3.brave.com/brave-browser-archive-keyring.gpg

echo "deb [signed-by=/usr/share/keyrings/brave-browser-archive-keyring.gpg arch=amd64] https://brave-browser-apt-release.s3.brave.com/ stable main"|sudo tee /etc/apt/sources.list.d/brave-browser-release.list

sudo apt update
sudo apt install vim git sxiv zathura mpv python3 python3-pip brave-browser nmap hydra texlive-full i3 i3blocks

pip install matplotlib pandas virtualenv

cd && rm -rf Movies Music Videos Pictures Documents 2>/dev/null && mkdir -p .ssh scripts Wallpapers Documents/templates Documents/lists

#Git
cd ~/Desktop/scripts && cp bandwidth.sh ~/scripts/ && cp -r i3 ~/scripts/ && cp linux_setup.sh ~/scripts/

cd ~/Desktop && git clone https://github.com/Veisakis/config
cd config/linux
cp .gitconfig ~ && cp .bashrc ~ && cp .vimrc ~ && cp i3/config ~/.config/i3/ && cp i3/i3blocks.conf /etc/

cd ~/Desktop && git clone https://github.com/Veisakis/latex
cp ~/Desktop/latex/templates ~/Documents/
cd ~/Desktop && rm -rf *
#Git

sudo apt update && sudo apt full-upgrade -y && sudo apt autoremove
