#Carlos 1Ruiz
#!/bin/bash

sudo apt install -y libluajit-5.1-dev

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi