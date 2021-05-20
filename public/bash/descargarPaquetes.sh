#Carlos 1Ruiz
#!/bin/bash


#Descargar paquetes
  #Crear Carpeta para organizar las descargas
  
if [ -d snort_src ]
	then
	cd snort_src/
	else
	sudo  mkdir snort_src
	sudo chown -R ubuntu:ubuntu snort
	cd snort_src/
fi

# if [ -d libsafec-02092020.0-g6d921f ]
# 	then
# 	cd snort_src/
# 	else
# 	sudo  mkdir snort_src
# 	sudo chown -R ubuntu:ubuntu snort
# 	cd snort_src/
# fi

  #Instalacion de Safec
	wget https://github.com/rurban/safeclib/releases/download/v02092020/libsafec-02092020.tar.gz
	tar -xzvf libsafec-02092020.tar.gz
	cd libsafec-02092020.0-g6d921f
	./configure
	make
	sudo make install
	cd ..

  #Instalacion de PCRE (Perl Compatible Regular Expresion)
	wget https://ftp.pcre.org/pub/pcre/pcre-8.44.tar.gz
	tar -xzvf pcre-8.44.tar.gz
	cd pcre-8.44
	./configure
	make
	sudo make install
	cd ..
  #Intallar gperftools 2.8	
	wget https://github.com/gperftools/gperftools/releases/download/gperftools-2.8/gperftools-2.8.tar.gz
	tar -xzvf gperftools-2.8.tar.gz
	cd gperftools-2.8
	./configure
	make
	sudo make install
	cd ..
  #Instalar Ragel
	wget http://www.colm.net/files/ragel/ragel-6.10.tar.gz
	tar -xzvf ragel-6.10.tar.gz
	cd ragel-6.10
	./configure
	make
	sudo make install
	cd ..
  #Descarga de Boost C++ Librearies
	wget https://boostorg.jfrog.io/artifactory/main/release/1.74.0/source/boost_1_74_0.tar.gz
	tar -xvzf boost_1_74_0.tar.gz
  #Instalar Hyperscan 5.3
  #error Hyperscan
	wget https://github.com/intel/hyperscan/archive/v5.3.0.tar.gz
	tar -xvzf v5.3.0.tar.gz
	mkdir hyperscan-5.3.0-build
	cd hyperscan-5.3.0-build/
	cmake -DCMAKE_INSTALL_PREFIX=/usr/local -DBOOST_ROOT=~/snort_src/boost_1_74_0/ ../hyperscan-5.3.0
	make
	sudo make install
	cd ..
  #Instalar flatbuffers
	wget https://github.com/google/flatbuffers/archive/v1.12.0.tar.gz -O flatbuffers-v1.12.0.tar.gz
	tar -xzvf flatbuffers-v1.12.0.tar.gz
	mkdir flatbuffers-build
	cd flatbuffers-build
	cmake ../flatbuffers-1.12.0
	make
	sudo make install
	cd ..
    
    
if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi
#   if [ -d snort ]
#   then
#     cd snort
#   else
#     sudo  mkdir snort
#     sudo chown -R ubuntu:ubuntu snort
#     cd snort
#   fi



# if [ -f snort-2.9.17.1.tar.gz ]
# then
#   if [ -f snort-2.9.17.1 ]
#   then
#     echo 'completa'
#   else
#     tar xvzf snort-2.9.17.1.tar.gz
#   fi
# else
#   wget https://www.snort.org/downloads/snort/snort-2.9.17.1.tar.gz
#   tar xvzf snort-2.9.17.1.tar.gz
#   if [ -f snort-2.9.17.1 ]
#   then
#     echo 'completa'
#   else
#     tar xvzf snort-2.9.17.1.tar.gz
#   fi
#   echo 'completa'
# fi
