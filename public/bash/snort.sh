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



if [ -f snort-2.9.17.1.tar.gz ]
then
  if [ -f snort-2.9.17.1 ]
  then
    echo 'completa'
  else
    tar xvzf snort-2.9.17.1.tar.gz
  fi
else
  wget https://www.snort.org/downloads/snort/snort-2.9.17.1.tar.gz
  tar xvzf snort-2.9.17.1.tar.gz
  if [ -f snort-2.9.17.1 ]
  then
    echo 'completa'
  else
    tar xvzf snort-2.9.17.1.tar.gz
  fi
  echo 'completa'
fi
