FROM alpine:3.12

WORKDIR /home

RUN apk update && apk add influxdb \
	&& apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/	\
	&& mkdir -p /var/lib/influxdb \
	&& mkdir -p /etc/influxdb && mkdir -p /etc/telegraf

RUN chown -R influxdb:influxdb /var/lib/influxdb

COPY ./start.sh /home/

COPY ./telegraf.conf /etc/telegraf/

VOLUME ["/var/lib/influxdb"]

EXPOSE 8086

ENTRYPOINT ["sh", "start.sh"]
