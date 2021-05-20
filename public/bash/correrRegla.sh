#Carlos 1Ruiz
#!/bin/bash
snort -c /usr/local/etc/snort/snort.lua -R /usr/local/etc/rules/local.rules

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi