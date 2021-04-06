FROM alpine:3.12

WORKDIR /var/www

RUN apk update && apk add nginx tar openssl telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ \
	&& mkdir -p /run/nginx && mkdir -p /etc/telegraf

RUN	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/nginx-selfsigned.key \
	-out /etc/ssl/certs/nginx-selfsigned.crt \
	-subj '/C=KR/ST=Seoul/L=Songpagu/O=Songpadaro/CN=127.0.0.1'

RUN adduser -D -g 'www' www && chown -R www:www /var/lib/nginx && chown -R www:www /var/www

COPY ./nginx.conf /etc/nginx/

COPY ./telegraf.conf /etc/telegraf/

COPY ./index.html /var/www/localhost

COPY ./start.sh /var/www/

EXPOSE 80 443

ENTRYPOINT ["sh", "start.sh"]
