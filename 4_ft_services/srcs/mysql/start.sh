telegraf --config /etc/telegraf/telegraf.conf &
if [ -z "$(ls -A /var/lib/mysql)" ]; then
	mysql_install_db --user=root --ldata=/var/lib/mysql
	mysqld --user=root --pid_file=/run/mysqld/mysqld.pid &
	sleep 2
	mysql -u root --skip-password < /home/wordpress.sql
	kill $(cat /run/mysqld/mysqld.pid)
	mysqld --user=root
else
	chown -R mysql:mysql /var/lib/mysql
	mysqld --user=root
fi	
