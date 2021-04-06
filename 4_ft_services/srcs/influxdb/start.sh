chown -R influxdb:influxdb /var/lib/influxdb
if [ -z "$(ls -A /var/lib/influxdb)" ]; then
	influxd run -config /etc/influxdb.conf -pidfile /run/influxdb.pid &
	sleep 2
	influx -execute "CREATE DATABASE influxdb"
	influx -execute "CREATE DATABASE mysql"
	influx -execute "CREATE DATABASE nginx"
	influx -execute "CREATE DATABASE grafana"
	influx -execute "CREATE DATABASE ftps"
	influx -execute "CREATE DATABASE phpmyadmin"
	influx -execute "CREATE DATABASE wordpress"
	influx -execute "CREATE USER influx_user WITH PASSWORD 'influx_password' WITH ALL PRIVILEGES"
	sleep 2
	kill $(cat /run/influxdb.pid)
fi	
telegraf --config /etc/telegraf/telegraf.conf &
influxd run -config /etc/influxdb.conf
