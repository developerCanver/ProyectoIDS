#Carlos 1Ruiz
#!/bin/bash

	wget https://github.com/snort3/libdaq/archive/refs/tags/v3.0.3.tar.gz
	tar -xzvf v3.0.3.tar.gz
	cd libdaq-3.0.3
	./bootstrap
	./configure
	make
	sudo make install
	cd ..

if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi