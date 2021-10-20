## PULLEDPORK Original
	sudo apt-get install -y libcrypt-ssleay-perl liblwp-useragent-determined-perl
## Descargamos la version de Pulledpork
	cd snort_src
	##wget https://github.com/shirkdog/pulledpork/archive/master.tar.gz -O pulledpork-master.tar.gz
	##tar xzvf pulledpork-master.tar.gz
	cd pulledpork-master
	sudo cp pulledpork.pl /usr/local/bin
	sudo chmod +x /usr/local/bin/pulledpork.pl
	sudo mkdir /usr/local/etc/pulledpork
	sudo cp etc/*.conf /usr/local/etc/pulledpork
##Verificar que esta correctamente instalado 
	/usr/local/bin/pulledpork.pl -V
## PulledPork v0.8.0 - The only positive thing to come out of 2020...well this and take-out liquor!
## Se realiza la siguiente configuracion dentro del archivo pulledpork.conf
## VALIDADO
	sudo vi /usr/local/etc/pulledpork/pulledpork.conf
		#La Linea19 se debe cambiar por la url de las reglas y el oinkcode de registro
		rule_url=https://www.snort.org/rules/|snortrules-snapshot.tar.gz|<oinkcode>
		#Se debe comentar la linea 21 con un #
		#rule_url=https://snort.org/downloads/community/|community-rules.tar.gz|Community
		#Linea 72
		rule_path=/usr/local/etc/rules/snort.rules
		#Linea 87 se cambia la ruta de la reglas locales
		local_rules=/usr/local/etc/rules/local.rules
		#linea 94 se cambia a dos el sid
		sid_msg_version=2
		#Linea 134 se coloca la version de la distrubucion del SO
		distro=Ubuntu-18-4
		#Linea 142 la lista de bloqueos
		block_list=/usr/local/etc/lists/default.blocklist
		#Linea 151
		IPRVersion=/usr/local/etc/lists
		#Linea209 ips politica
		ips_policy=ballanced
	#Se guarda y se sale del archivo de configuracion y se aplica el siguiente comando
	sudo /usr/local/bin/pulledpork.pl -c /usr/local/etc/pulledpork/pulledpork.conf -l -P -E -T
#Nos muestra los registros de las reglas que se encuentran en funcionamiento
#Aplicamos un creador de tareas para actualizar las reglas automaticamente
	sudo crontab -e
	44 13 * * * /usr/local/bin/pulledpork.pl -c /usr/local/etc/pulledpork/pulledpork.conf -l -P -E -T
#Modificamos el snort.lua 
 	nano /usr/local/etc/snort/snort.lua
	#modicamos la linea de ips
		ips =
		{
			enable_builtin_rules = true,
			include = RULE_PATH .. "/snort.rules",
			variables = default_variables
		}
	#Salimos y guardamos el archivo
	sudo snort -c /usr/local/etc/snort/snort.lua
##Configuracion de los plugins de Snort
	sudo vi /usr/local/etc/snort/snort.lua
	#Ingresamos la direccion de la red
	HOME_NET = '10.0.0.0/24'
	#modificamos el hyperscan en la linea 104 aproximadamente en caso de tenerlo de lo contrario no lo agregamso
	search_engine = { search_method = "hyperscan" }

	detection = {
	hyperscan_literals = true,
	pcre_to_regex = true
	}
	#cambiamos la reputacion en la linea 96
	reputation =
	{
	blocklist = BLACK_LIST_PATH .. "/default.blocklist",
	} 
	#Cerramos y guardamos el archivos 
	sudo snort -c /usr/local/etc/snort/snort.lua
##Configuramos el plugin de alertas JSON en la linea 230 aproximadamente
	sudo vi /usr/local/etc/snort/snort.lua
	alert_json =
	{
	file = true,
	limit = 100,
	fields = 'seconds action class b64_data dir dst_addr dst_ap dst_port eth_dst eth_len \
	eth_src eth_type gid icmp_code icmp_id icmp_seq icmp_type iface ip_id ip_len msg mpls \
	pkt_gen pkt_len pkt_num priority proto rev rule service sid src_addr src_ap src_port \
	target tcp_ack tcp_flags tcp_len tcp_seq tcp_win tos ttl udp_len vlan timestamp',
	}
	#Guardamos y salimos del archivo
#ejecutamos el comado para cativar 
sudo /usr/local/bin/snort -c /usr/local/etc/snort/snort.lua -s 65535 \
-k none -l /var/log/snort -i ens3 -m 0x1b
#Creamos el archivo alert_json.txt y adicionamos toda esta información
cat /var/log/snort/alert_json.txt
	{ "seconds" : 1608147213, "action" : "allow", "class" : "none", "b64_data" : "
	DWHaXwAAAADO0wgAAAAAABAREhMUFRYXGBkaGxwdHh8gISIjJCUmJygpKissLS4vMDEyMzQ1Njc=", "dir" : "S2C", "
	dst_addr" : "10.10.10.1", "dst_ap" : "10.10.10.1:0", "eth_dst" : "52:54:00:1F:8A:1C", "eth_len" :
	98, "eth_src" : "52:54:00:70:78:9F", "eth_type" : "0x800", "gid" : 1, "icmp_code" : 0, "icmp_id" :
	5203, "icmp_seq" : 3, "icmp_type" : 0, "iface" : "ens3", "ip_id" : 3006, "ip_len" : 64, "msg" : "
	ICMP Traffic Detected", "mpls" : 0, "pkt_gen" : "raw", "pkt_len" : 84, "pkt_num" : 8, "priority" :
	0, "proto" : "ICMP", "rev" : 0, "rule" : "1:10000001:0", "service" : "unknown", "sid" : 10000001, "
	src_addr" : "10.10.10.88", "src_ap" : "10.10.10.88:0", "tos" : 0, "ttl" : 64, "vlan" : 0, "
	timestamp" : "12/16-20:33:33.603502" }
##Creamos el script para que snort se auto ejecute
	sudo froupadd snort 
	sudo useradd snort -r -s /sbin/nologin -c SNORT_IDS -g snort
#removemos todos los anteriores registros
	sudo rm /var/log/snort/*
#damos todos los permisos a snort
	sudo chmod -R 5775 /var/log/snort
	sudo chown -R snort:snort /var/log/snort
#creamos el servicio de snort
	sudo vi /lib/systemd/system/snort3.service
#Activamos el servicio
	sudo systemctls enable snort3
	sudo service snort3 start
	service snort3 status 
	sudo journalctl -u snort3.service
##Instalacion del GUI la interfaz Grafica SPLUNK
	sudo wget -O splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb 'https://d7wz6hmoaavd0.cloudfront.net/products/splunk/releases/8.2.2.1/linux/splunk-8.2.2.1-ae6821b7c64b-linux-2.6-amd64.deb'
	sudo chown -R splunk:splunk /opt/splunk
	sudo /opt/splunk/bin/splunk start --answer-yes --accept-license
	sudo /opt/splunk/bin/splunk stop
	sudo /opt/splunk/bin/splunk enable boot-start -systemd-managed 1
	sudo chown -R splunk:splunk /opt/splunk
	sudo service Splunkd start


if [ $? -eq 0 ]
  then 
    exit 0
  else
    echo 'ERROR'    
fi