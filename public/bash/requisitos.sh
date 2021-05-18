#Carlos 1Ruiz
#!/bin/bash

sudo mkdir /usr/local/etc/rules 
sudo mkdir /usr/local/etc/so_rules/ 
sudo mkdir /usr/local/etc/lists/ 
sudo touch /usr/local/etc/rules/snort.rules 
sudo touch /usr/local/etc/rules/local.rules 
sudo touch /usr/local/etc/lists/default.blocklist 
sudo mkdir /var/log/snort

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi