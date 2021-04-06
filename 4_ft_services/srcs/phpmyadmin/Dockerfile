FROM alpine:3.12

WORKDIR /var/www

RUN apk upgrade && apk add wget tar nginx php php7-fpm \
	php7-common php7-iconv php7-json php7-gd php7-curl php7-xml \
	php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql \
	php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext \
	php7-ldap php7-ctype php7-dom php7-session php7-mbstring \
	telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/

RUN mkdir -p /run/nginx && adduser -D -g 'www' www \
	&& chown -R www:www /var/lib/nginx \
	&& chown -R www:www /var/www \
	&& mkdir -p /etc/telegraf

COPY ./phpMyAdmin-4.9.2-all-languages.tar.gz /var/www

RUN tar -xzvf phpMyAdmin-4.9.2-all-languages.tar.gz \
	&& rm phpMyAdmin-4.9.2-all-languages.tar.gz \
	&& mv phpMyAdmin-4.9.2-all-languages phpmyadmin \
	&& mkdir -p /var/www/phpmyadmin/tmp/ \
	&& chown -R www:www /var/www/phpmyadmin/tmp/ \
	&& chmod 777 /var/www/phpmyadmin/tmp/

COPY ./nginx.conf /etc/nginx/

COPY ./start.sh /var/www/

COPY ./config.inc.php /var/www/phpmyadmin/

COPY ./telegraf.conf /etc/telegraf/

EXPOSE 5000

ENTRYPOINT ["sh", "start.sh"]
