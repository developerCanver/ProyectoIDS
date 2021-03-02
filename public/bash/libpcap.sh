#Carlos 1Ruiz
#!/bin/bash
#sudo apt-get install libpcap-dev
sudo apt-get install -y libpcap-dev 
if [ $? -eq 0 ]
  then 
    exit 0
  else
 yes | sudo fuser -vki /var/lib/dpkg/lock-frontend
  ''
  sudo rm -rf /var/lib/dpkg/lock
  sudo dpkg --configure -a
  sudo apt autoremove
  sudo apt-get install -y libpcap-dev 
    echo 'Error de cargar libreria'    
fi