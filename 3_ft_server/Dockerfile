FROM    debian:buster

LABEL   maintainer="hyungjki@student.42seoul.kr"

RUN    	apt-get update && apt-get upgrade && apt-get install -y \
    	nginx \
    	mariadb-server \
    	php-fpm \
    	php-mysql \
    	php-mbstring \
    	openssl \
    	vim
	
COPY    srcs/nginx.conf /etc/nginx/sites-available/ft_server
COPY    srcs/config.inc.php /var
COPY    srcs/wp-config.php /var
COPY    srcs/phpMyAdmin-5.0.2.tar.gz ./
COPY    srcs/wordpress.tar.gz ./
COPY    srcs/init.sh ./

EXPOSE  80 443

CMD    	bash init.sh