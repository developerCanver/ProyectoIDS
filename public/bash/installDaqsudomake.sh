#Carlos 1Ruiz
#!/bin/bash
cd snort
cd daq-2.0.7/
autoreconf -f -i
#instalacion de 2 paquete DAQ
sudo make install

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi