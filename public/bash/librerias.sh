#Carlos 1Ruiz
#!/bin/bash

sudo  apt install -y build-essential libpcap-dev libpcre3-dev libnet1-dev zlib1g-dev luajit hwloc libdnet-dev libdumbnet-dev bison flex liblzma-dev openssl libssl-dev pkg-config libhwloc-dev cmake cpputest libsqlite3-dev uuid-dev libcmocka-dev libnetfilter-queue-dev libmnl-dev autotools-dev libluajit-5.1-dev libunwind-dev
sudo apt install -y cmake 
sudo apt-get  install ethtool
sudo apt install net-tools
if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi