#Carlos 1Ruiz
#!/bin/bash
sudo apt-get update
sudo apt-get upgrade -y

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi