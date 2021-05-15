#Carlos 1Ruiz
#!/bin/bash

  if [ -d snort ]
  then
    cd snort
  else
    sudo  mkdir snort
    sudo chown -R ubuntu:ubuntu snort
    cd snort
  fi

if [ -f daq-2.0.7.tar.gz ]
then
  if [ -f daq-2.0.7 ]
  then
    echo 'completa'
  else
    tar xvzf daq-2.0.7.tar.gz
  fi
else
  wget wget https://www.snort.org/downloads/snort/daq-2.0.7.tar.gz
  tar xvzf daq-2.0.7.tar.gz
  if [ -f daq-2.0.7 ]
  then
    echo 'completa'
  else
    tar xvzf daq-2.0.7.tar.gz
  fi
  echo 'completa'
fi