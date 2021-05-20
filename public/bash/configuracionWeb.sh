#Carlos 1Ruiz
#!/bin/bash
sudo ethtool -k enp0s3 | grep receive-offload
sudo cp /home/ubuntu/code/ProyectoIDS/public/ethtool.service /lib/systemd/system/
sudo systemctl enable ethtool
sudo service ethtool start

#ethtool -K enp0s3 gro off lro off

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi