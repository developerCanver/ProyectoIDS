#Carlos 1Ruiz
#!/bin/bash

cd snort-2.9.17/
sudo apt-get install -y libpcre3-dev 

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi