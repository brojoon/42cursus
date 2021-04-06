minikube delete
minikube start --driver=docker
eval $(minikube docker-env)

minikube addons enable metrics-server
minikube addons enable dashboar
kubectl get configmap kube-proxy -n kube-system -o yaml | sed -e "s/strictARP: false/strictARP: true/" | kubectl diff -f - -n kube-system
minikube addons enable metallb

MINIKUBE_IP="$(kubectl get node -o=custom-columns='DATA:status.addresses[0].address' | sed -n 2p)"

sed -i -e "s/setminikubeip/$MINIKUBE_IP/g" srcs/yaml/metallb.yaml
kubectl apply -f srcs/yaml/metallb.yaml
sed -i -e "s/$MINIKUBE_IP/setminikubeip/g" srcs/yaml/metallb.yaml


docker build -t image-mysql --build-arg minikube_ip=$MINIKUBE_IP srcs/mysql
docker build -t image-influxdb srcs/influxdb
docker build -t image-nginx srcs/nginx
docker build -t image-wordpress srcs/wordpress
docker build -t image-phpmyadmin srcs/phpmyadmin
docker build -t image-ftps --build-arg minikube_ip=$MINIKUBE_IP srcs/ftps
docker build -t image-grafana srcs/grafana

kubectl apply -f srcs/yaml/mysql.yaml
kubectl apply -f srcs/yaml/influxdb.yaml
kubectl apply -f srcs/yaml/nginx.yaml
kubectl apply -f srcs/yaml/wordpress.yaml
kubectl apply -f srcs/yaml/phpmyadmin.yaml
kubectl apply -f srcs/yaml/ftps.yaml
kubectl apply -f srcs/yaml/grafana.yaml

minikube dashboard
