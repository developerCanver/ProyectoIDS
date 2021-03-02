#Carlos 1Ruiz
#!/bin/bash

cd snort-2.9.17/
autoreconf -f -i
./configure
 #echo "${pwd##*/}"
#echo "${"
#printf '%s'
#echo "${ifconfig##*/}"

#ping -c30 -i3 8.8.8.8
#if [ $? -eq 0 ]
#then 
#exit 0
#else echo “fail”
#fi

#ping -c1 8.8.8.8 
if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi