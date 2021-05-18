#Carlos 1Ruiz
#!/bin/bash
sudo apt install ethtool
sudo ip link set dev enp0s3 promisc on
sudo ip add sh enp0s3
sudo ethtool -k enp0s3 | grep receive-offload
#ethtool -K enp0s3 gro off lro off

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi