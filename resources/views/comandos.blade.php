#Actualizar Sistemas
    sudo apt-get update
    sudo apt-get upgrade -y
#Descargar Librerias
    apt install build-essential libpcap-dev libpcre3-dev libnet1-dev zlib1g-dev luajit hwloc libdnet-dev libdumbnet-dev bison flex liblzma-dev openssl libssl-dev pkg-config libhwloc-dev cmake cpputest libsqlite3-dev uuid-dev libcmocka-dev libnetfilter-queue-dev libmnl-dev autotools-dev libluajit-5.1-dev libunwind-dev
#Descargar paquetes
  #Crear Carpeta para organizar las descargas
    mkdir snort_src
    cd /snort_src
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
#Intalar DAQ
    wget https://github.com/snort3/libdaq/archive/refs/tags/v3.0.3.tar.gz
    tar -xzvf v3.0.3.tar.gz
##confirmar    cd libdaq-3.0.3
    ./bootstrap
    ./configure
    make
    sudo make install
    cd ..
#Instalar Snort
    wget https://github.com/snort3/snort3/archive/refs/tags/3.1.4.0.tar.gz
    tar -xzvf 3.1.4.0.tar.gz
##Corregir    cd snort3-3.1.0.0
    ./configure_cmake.sh --prefix=/usr/local --enable-tcmalloc
    cd build
    make
    sudo make install
    cd ..
    snort -V // Confirmar que la instalación quedo bien configurada
#Comprobar que snort esta corriendo con la configuracion por defecto
    snort -c /usr/local/etc/snort/snort.lua
        //Snort successfully validated the configuration (with 0 warnings).
        //o")~ Snort exiting
#Configuracion de Red
    sudo ethtool -k ens3 | grep receive-offload
    // Se crea este archivo ethtool.service
    sudo vi /lib/systemd/system/ethtool.service
        [Unit]
        Description=Ethtool Configration for Network Interface
        [Service]
        Requires=network.target
        Type=oneshot
        ExecStart=/sbin/ethtool -K ens3 gro off
        ExecStart=/sbin/ethtool -K ens3 lro off
        [Install]
        WantedBy=multi-user.target
    sudo systemctl enable ethtool
    sudo service ethtool start
#Prerequisitos de Reglas
    sudo mkdir /usr/local/etc/rules
    sudo mkdir /usr/local/etc/so_rules/
    sudo mkdir /usr/local/etc/lists/
    sudo touch /usr/local/etc/rules/snort.rules
    sudo touch /usr/local/etc/rules/local.rules
    sudo touch /usr/local/etc/lists/default.blocklist
    sudo mkdir /var/log/snort
#Prueba de funcionamiento de regla Modificar el archivo
    sudo vi /usr/local/etc/rules/local.rules
        alert icmp any any -> any any ( msg:"ICMP Traffic Detected"; sid:10000001; metadata:policy security-ips alert; )
    snort -c /usr/local/etc/snort/snort.lua -R /usr/local/etc/rules/local.rules
