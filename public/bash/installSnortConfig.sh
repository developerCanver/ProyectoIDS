#Carlos 1Ruiz
#!/bin/bash

#Instalar Snort
cd snort_src
	wget https://github.com/snort3/snort3/archive/refs/tags/3.1.4.0.tar.gz
	tar -xzvf 3.1.4.0.tar.gz
	cd snort3-3.1.4.0
	./configure_cmake.sh --prefix=/usr/local --enable-tcmalloc
	cd build
	make
	sudo make install
	cd ..
#ping -c1 8.8.8.8 
if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi