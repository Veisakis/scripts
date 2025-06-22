#!/bin/bash
#First create a Linode VPC with the latest stable Ubuntu release.
#Purchase a domain name and map its A/AAAA Record to the Public Static IP of the VPC.
#
#Connect with ssh to the server and run the following script.

read -p "Username: " $USERNAME
read -p "Domain: " $DOMAIN

apt update
apt install apache2 certbot python3-certbot-apache

certbot --apache -d $DOMAIN
#It should automatically renew the certificate.
#If not, edit the cron file and add the line with the asterisks for a monthly renewal.
#crontab -e
#**1** certbot renew

#Create a user and add him to the admin group.
useradd -d /home/$USERNAME -s /bin/bash -G admin $USERNAME
passwd $USERNAME

chown -R $USERNAME:admin /home/$USERNAME /var/www

#Modify the /etc/ssh/sshd_config file to disable root login.
#Optionally disable password login and allow only public key authentication.
mkdir /home/$USERNAME/.ssh
#From the local PC, copy the admin's public key to the remote PC.
#scp ~/.ssh/id_rsa.pub user@ip:/home/user/.ssh/uploaded_key.pub
#cat uploaded_key.pub >> authorized_keys
#chmod 700 /home/$USERNAME/.ssh
#chmod 600 /home/$USERNAME/.ssh/*

echo wb='cd /var/www' >> /home/$USERNAME/.bashrc
echo ls='ls --color' >> /home/$USERNAME/.bashrc
source /home/$USERNAME/.bashrc

#Configure a basic firewall scheme.
#Download the firewall file from github and run the following command.
apt install iptables-persistent
chmod +x firewall
./firewall
iptables-save >> /etc/iptables/rules.v4

#Include the email address and password of the sender account 
#(the gmail account needs to be setup with 2FA and APP ACCESS enabled for the password) 
#and the email address of the receiver 
#in the bashrc file by using the export command to make it a global not a local variable.

#Use the flask app found in the "co-web" repository in github.
