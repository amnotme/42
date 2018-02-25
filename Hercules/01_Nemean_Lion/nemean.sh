#!/bin/bash

#ensure that the user is in root.
if [[ $EUID -ne 0 ]]; then
	echo "You are not in root!"
	exit 1
fi
#get openssh-server package
apt-get install openssh-server -y
#make a backup
cp /etc/ssh/sshd_config /etc/ssh/sshd_config_backup
#substitue the line #Port 22 for Port 1234 using sed
#Option -i means extension (to be able to read the sshd_config file 
sed -i "s/#Port 22/Port 1234/" /etc/ssh/sshd_config
#Finally. Restart the server.
service ssh restart
