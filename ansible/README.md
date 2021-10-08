1. nmap 192.168.1.0/24 to find pi's IP
2. Set it to static IP 192.168.1.13
3. ssh-copy-id -i ~/.ssh/id_rsa.pub pi@192.168.1.13
4. execute "ansible-playbook --ask-become-pass site.yaml"
