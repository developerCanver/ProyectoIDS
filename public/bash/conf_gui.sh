## PULLEDPORK Original
#	sudo apt-get install -y libcrypt-ssleay-perl liblwp-useragent-determined-perl
## Descargamos la version de Pulledpork



	cd interfaz/
	

if [ -d pulledpork-master ]
	then
		sudo cp pulledpork.conf /usr/local/etc/pulledpork/pulledpork.conf
		cd pulledpork-master/
		
	else
		wget https://github.com/shirkdog/pulledpork/archive/master.tar.gz -O pulledpork-master.tar.gz
		tar xzvf pulledpork-master.tar.gz
		sudo cp pulledpork.conf /usr/local/etc/pulledpork/pulledpork.conf
		cd pulledpork-master/	
fi

	sudo cp pulledpork.pl /usr/local/bin
	sudo chmod +x /usr/local/bin/pulledpork.pl

	sudo mkdir /usr/local/etc/pulledpork


	sudo cp etc/*.conf /usr/local/etc/pulledpork
##Verificar que esta correctamente instalado 
#	/usr/local/bin/pulledpork.pl -V
## PulledPork v0.8.0 - The only positive thing to come out of 2020...well this and take-out liquor!

#Nos muestra los registros de las reglas que se encuentran en funcionamiento
#Aplicamos un creador de tareas para actualizar las reglas automaticamente
	sudo /usr/local/bin/pulledpork.pl -c /usr/local/etc/pulledpork/pulledpork.conf -l -P -E -T

	cd ..

	
#Nos muestra los registros de las reglas que se encuentran en funcionamiento
#Aplicamos un creador de tareas para actualizar las reglas automaticamente
#	sudo crontab -e
#	44 13 * * * /usr/local/bin/pulledpork.pl -c /usr/local/etc/pulledpork/pulledpork.conf -l -P -E -T
#Modificamos el snort.lua 
 	#nano /usr/local/etc/snort/snort.lua
	sudo cp snort.lua /usr/local/bin
	sudo snort -c /usr/local/etc/snort/snort.lua
	sudo cp alert_json.txt /var/log/snort/

#	cd pulledpork-master/
    sudo /usr/local/bin/snort -c /usr/local/etc/snort/snort.lua -s 65535 -k none -l /var/log/snort -i ens3 -m 0x1b
#   sudo /usr/local/bin/snort -c /usr/local/etc/snort/snort.lua -s 65535 -k none -l /var/log/snort -i enp0s3 -m 0x1b

	sudo snort -c /usr/local/etc/snort/snort.lua

##Creamos el script para que snort se auto ejecute
	sudo groupadd snort 
	sudo useradd snort -r -s /sbin/nologin -c SNORT_IDS -g snort
#removemos todos los anteriores registros
	sudo rm /var/log/snort/*
#damos todos los permisos a snort
	sudo chmod -R 5775 /var/log/snort
	sudo chown -R snort:snort /var/log/snort
#creamos el servicio de snort

	#sudo vi /lib/systemd/system/snort3.service
	sudo cp snort3.service /lib/systemd/system/snort3.service

#Activamos el servicio
	sudo systemctls enable snort3
	sudo service snort3 start
	service snort3 status 
	sudo journalctl -u snort3.service


##Instalacion del GUI la interfaz Grafica SPLUNK
	

if [ -f splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb ]
	then
	sudo dpkg -i splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb
	else
	sudo wget -O splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb 'https://d7wz6hmoaavd0.cloudfront.net/products/splunk/releases/8.2.2.1/linux/splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb'
	sudo dpkg -i splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb
fi

	sudo chown -R splunk:splunk /opt/splunk	
	#asignar usuario : ids, contraseña ids12345
	sudo /opt/splunk/bin/splunk start --answer-yes --accept-license -Y

	sudo /opt/splunk/bin/splunk stop
	sudo /opt/splunk/bin/splunk enable boot-start -systemd-managed 1 -Y
	sudo chown -R splunk:splunk /opt/splunk
	#Correr el programa 
	#sudo service Splunkd start

	#Configuracion de adicional para Splucnk

	#sudo mkdir /opt/splunk/etc/apps/TA_Snort3_json/local

	sudo mkdir /opt/splunk/etc/apps/TA_Snort3_json
	sudo mkdir /opt/splunk/etc/apps/TA_Snort3_json/local

	cd config/

	
	#Copiar el archivo inputs 
	sudo cp inputs.conf /opt/splunk/etc/apps/TA_Snort3_json/local/inputs.conf
	#Reiniciar el servicio
	sudo service Splunkd restart
	#Limpiar la instalción de SPLUNK 
	sudo apt-get install -y apache2 apache2-utils
	sudo a2enmod proxy
	sudo a2enmod proxy_http
	sudo systemctl restart apache2
	sudo touch /etc/apache2/.htpasswd

	#usuario y contraseña
	#sudo htpasswd /etc/apache2/.htpasswd ids
	#contraseña: ids12345
	#Copiar el archivo 000-default.conf
	sudo cp 000-default.conf /etc/apache2/sites-available/000-default.conf
	#Verificar la configuracion de Apache
	sudo apachectl -t
	#Reiniciar Apache
	sudo systemctl restart apache2
	#Configurar para que splunk acepte conexiones locales
	#Copiamos el archivo
	sudo cp web.conf /opt/splunk/etc/system/local/web.conf
	#Reiniciamos el servicio Splunkd
	sudo service Splunkd restart


if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi