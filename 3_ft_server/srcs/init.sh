#!/bin/bash



ln -s /etc/nginx/sites-available/ft_server /etc/nginx/sites-enabled/

rm -rf /etc/nginx/sites-enabled/default



mkdir /etc/nginx/ssl



openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \

			-subj "/CN=localhost" \

			-out /etc/nginx/ssl/localhost.crt \

			-keyout /etc/nginx/ssl/localhost.key



chmod 600 /etc/nginx/ssl/*



service mysql start



echo "CREATE DATABASE wordpress;" \

		| mysql -u root

echo "CREATE USER 'hyungjki'@'localhost' IDENTIFIED BY 'hyungjki';" \

		| mysql -u root

echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'hyungjki'@'localhost' WITH GRANT OPTION" \

		| mysql -u root



path="/var/www/html"



mkdir ${path}



tar -xvf phpMyAdmin-5.0.2.tar.gz

mv -f phpMyAdmin-5.0.2-all-languages ${path}/phpmyadmin

mv /var/config.inc.php ${path}/phpmyadmin/



tar -xvf wordpress.tar.gz

mv -f wordpress/ ${path}

mv /var/wp-config.php ${path}/wordpress

chown -R www-data:www-data ${path}/wordpress



service php7.3-fpm start

service nginx start



mysql < ${path}/phpmyadmin/sql/create_tables.sql



bash
