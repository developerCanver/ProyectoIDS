#Carlos 1Ruiz
#!/bin/bash
 cd snort
cd daq-2.0.7/
sudo dpkg --configure -a
sudo apt-get install build-essential -y
autoreconf -f -i
./configure

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi