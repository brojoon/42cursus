FROM alpine:3.12

WORKDIR /home

ARG minikube_ip

RUN apk upgrade && apk add vsftpd openssl telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/ && mkdir -p /etc/telegraf

RUN { echo "ftp_password"; echo "ftp_password"; } | adduser ftp_user

RUN	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/vsftpd.key \
	-out /etc/ssl/certs/vsftpd.crt \
	-subj '/C=KR/ST=Seoul/L=Songpagu/O=Songpadaro/CN=127.0.0.1'

COPY ./vsftpd.conf /etc/vsftpd/ 

RUN sed -i -e "s/setminikubeip/$minikube_ip/g" /etc/vsftpd/vsftpd.conf

COPY ./telegraf.conf /etc/telegraf/

COPY ./start.sh /home/

EXPOSE 21 20 30000 30001

CMD ["sh", "start.sh"]
