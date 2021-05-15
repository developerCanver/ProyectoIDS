#Carlos 1Ruiz
#!/bin/bash

cd snort
cd snort-2.9.17.1/
autoreconf -f -i
./configure --enable-sourcefire && make && sudo make install
#ldconfig


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