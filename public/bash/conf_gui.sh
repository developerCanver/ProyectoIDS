## PULLEDPORK Original
	sudo apt-get install -y libcrypt-ssleay-perl liblwp-useragent-determined-perl
## Descargamos la version de Pulledpork
	cd interfaz
	
	
if [ -d pulledpork-master ]
	then
	else
	wget https://github.com/shirkdog/pulledpork/archive/master.tar.gz -O pulledpork-master.tar.gz
	tar xzvf pulledpork-master.tar.gz
	
fi

	sudo cp pulledpork.pl /usr/local/bin
	cd pulledpork-master
	sudo chmod +x /usr/local/bin/pulledpork.pl
	sudo mkdir /usr/local/etc/pulledpork
	sudo cp etc/*.conf /usr/local/etc/pulledpork
##Verificar que esta correctamente instalado 
	/usr/local/bin/pulledpork.pl -V
## PulledPork v0.8.0 - The only positive thing to come out of 2020...well this and take-out liquor!

	sudo /usr/local/bin/pulledpork.pl -c /usr/local/etc/pulledpork/pulledpork.conf -l -P -E -T

	cd ..
#Nos muestra los registros de las reglas que se encuentran en funcionamiento
#Aplicamos un creador de tareas para actualizar las reglas automaticamente
#	sudo crontab -e
#	44 13 * * * /usr/local/bin/pulledpork.pl -c /usr/local/etc/pulledpork/pulledpork.conf -l -P -E -T
#Modificamos el snort.lua 
 	#nano /usr/local/etc/snort/snort.lua
	sudo cp snort.lua /usr/local/bin
	cd pulledpork-master
sudo /usr/local/bin/snort -c /usr/local/etc/snort/snort.lua -s 65535 \
-k none -l /var/log/snort -i ens3 -m 0x1b
#Creamos el archivo alert_json.txt y adicionamos toda esta información
cd ..
sudo cp alert_json.txt /var/log/snort/alert_json.txt
cd pulledpork-master
# cat /var/log/snort/alert_json.txt
# 	{ "seconds" : 1608147213, "action" : "allow", "class" : "none", "b64_data" : "
# 	DWHaXwAAAADO0wgAAAAAABAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc=", "dir" : "S2C", "
# 	dst_addr" : "10.10.10.1", "dst_ap" : "10.10.10.1:0", "eth_dst" : "52:54:00:1F:8A:1C", "eth_len" :
# 	98, "eth_src" : "52:54:00:70:78:9F", "eth_type" : "0x800", "gid" : 1, "icmp_code" : 0, "icmp_id" :
# 	5203, "icmp_seq" : 3, "icmp_type" : 0, "iface" : "ens3", "ip_id" : 3006, "ip_len" : 64, "msg" : "
# 	ICMP Traffic Detected", "mpls" : 0, "pkt_gen" : "raw", "pkt_len" : 84, "pkt_num" : 8, "priority" :
# 	0, "proto" : "ICMP", "rev" : 0, "rule" : "1:10000001:0", "service" : "unknown", "sid" : 10000001, "
# 	src_addr" : "10.10.10.88", "src_ap" : "10.10.10.88:0", "tos" : 0, "ttl" : 64, "vlan" : 0, "
# 	timestamp" : "12/16-20:33:33.603502" }
##Creamos el script para que snort se auto ejecute
	sudo froupadd snort 
	sudo useradd snort -r -s /sbin/nologin -c SNORT_IDS -g snort
#removemos todos los anteriores registros
	sudo rm /var/log/snort/*
#damos todos los permisos a snort
	sudo chmod -R 5775 /var/log/snort
	sudo chown -R snort:snort /var/log/snort





#creamos el servicio de snort
# 	sudo vi /lib/systemd/system/snort3.service
# #Activamos el servicio
# 	sudo systemctls enable snort3
# 	sudo service snort3 start
# 	service snort3 status 
# 	sudo journalctl -u snort3.service
# ##Instalacion del GUI la interfaz Grafica SPLUNK
# 	sudo wget -O splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb 'https://d7wz6hmoaavd0.cloudfront.net/products/splunk/releases/8.2.2.1/linux/splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb'
# 	sudo chown -R splunk:splunk /opt/splunk
# 	sudo /opt/splunk/bin/splunk start --answer-yes --accept-license
# 	sudo /opt/splunk/bin/splunk stop
# 	sudo /opt/splunk/bin/splunk enable boot-start -systemd-managed 1
# 	sudo chown -R splunk:splunk /opt/splunk
# 	sudo service Splunkd start


if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi