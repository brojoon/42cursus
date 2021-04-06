FROM alpine:3.12

WORKDIR /home

ARG minikube_ip

RUN apk update && apk add mariadb mariadb-client mariadb-server-utils \
    telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ \
	&& mkdir -p /etc/telegraf && mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

COPY ./wordpress.sql /home/

RUN sed -i -e "s/192.168.49.50/$minikube_ip/g" /home/wordpress.sql

COPY ./start.sh /home/

COPY ./my.cnf /etc/

COPY ./telegraf.conf /etc/telegraf/

EXPOSE 3306

VOLUME ["/var/lib/mysql"]

CMD ["sh", "start.sh"]
