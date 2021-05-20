#Carlos 1Ruiz
#!/bin/bash


#Intalar DAQ
if [ -d snort_src ]
	then
	cd snort_src
	else
	sudo  mkdir snort_src
	sudo chown -R ubuntu:ubuntu snort
	cd snort_src
fi



if [ -d libdaq-3.0.3 ]
	then
	 if [ -f v3.0.3.tar.gz ]
	then	
	else
		
		tar -xzvf v3.0.3.tar.gz
		cd libdaq-3.0.3
		./bootstrap
		./configure
		make
		sudo make install
		cd ..
	fi
else
		wget https://github.com/snort3/libdaq/archive/refs/tags/v3.0.3.tar.gz
		tar -xzvf v3.0.3.tar.gz
		cd libdaq-3.0.3
		./bootstrap
		./configure
		make
		sudo make install
		cd ..
fi


if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi

