#Carlos 1Ruiz
#!/bin/bash

sudo apt-get install -y zlib1g-dev

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi