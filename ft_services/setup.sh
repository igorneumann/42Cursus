source $HOME/.zshrc

if [[ $srcs == "" ]];
then
	#get current path
	CPATH=$PWD
	srcs=$PWD/srcs
fi

#INSTALL IF NECESARY
if [ ! -d "/Applications/Docker.app" ] && [ ! -d "~/Applications/Docker.app" ]; then
	./install.sh
fi
which -s virtualbox
if [[ $? != 0 ]]; then
	./install.sh
fi
which -s docker-machine
if [[ $? != 0 ]] ; then
	./install.sh
fi

#Prune Docker
if [[ $1 == "nuke" ]]
	then
	echo ""
	read -t 4 -p "Nuke all this Shit? [Y/${cyan}n${blue}]${reset}" input
	echo ""
	if [ -n "$input" ] && [ "$input" != "n" ];
		then
		cd $srcs/yaml/
		kubectl delete -f influxdb-deployment.yaml
		kubectl delete -f grafana-deployment.yaml
		enable -n echo
		echo ""
		echo -n "."
		kubectl delete -f nginx-deployment.yaml
		kubectl delete -f mysql-deployment.yaml
		echo -n "."
		kubectl delete -f mysql-deployment.yaml
		kubectl delete -f wordpress-deployment.yaml
		echo -n "."
		kubectl delete -f phpmyadmin-deployment.yaml
		kubectl delete -f ftps-deployment.yaml
		echo -n "."
		kubectl delete -f telegraf-deployment.yaml
		kubectl delete -f volumes.yaml
		echo -n "."
		kubectl delete -f metallb.yaml
		kubectl delete -f loadbalance.yaml
		echo -n "."
		eval $(minikube docker-env)
		docker stop $(docker ps -a -q)
		minikube stop
		echo -n "."
		yes | docker system prune -a
		echo -n "."
		sleep 0.1
		echo -n "."
		sleep 0.1
		echo -n "."
		sleep 0.1
		echo "*"
		sleep 0.1
		echo ""
		echo "BOOM, your shit is gone now!"
		echo ""
	fi
fi

#detect 1st run
FIRSTRUN=$(kubectl get secrets)

#start minikube if no images available
if [[ $FIRSTRUN == "" ]];
then
	minikube start --vm-driver virtualbox --extra-config=apiserver.service-node-port-range=1-35000
	kubectl proxy &
	cd $srcs/yaml/ && \ 
	kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.9.3/manifests/namespace.yaml
	kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
	minikube addons enable metrics-server && \
	minikube addons enable dashboard
fi

cd $srcs/yaml/ 
kubectl apply -f volumes.yaml 
kubectl apply -f metallb.yaml
kubectl apply -f loadbalance.yaml

#Cambiar entorno
eval $(minikube docker-env)

#set variables
SSH_USERNAME=admin
SSH_PASSWORD=admin
FTPS_USERNAME=admin
FTPS_PASSWORD=admin
DB_USER=newuser
DB_PASSWORD=password

if [[ $MINIKUBE_IP == "" ]];
then
	#Get IP
	minikube ip > /tmp/.minikube.ip
	MINIKUBE_IP=`cat /tmp/.minikube.ip`;
fi

#Check if images exist
eval $(minikube docker-env)
NGINX_IMAGE=$(docker images -q ft_nginx)
MYSQL_IMAGE=$(docker images -q ft_mysql)
WORDPRESS_IMAGE=$(docker images -q ft_wordpress)
PHPMYADMIN_IMAGE=$(docker images -q ft_phpmyadmin)
FTPS_IMAGE=$(docker images -q ft_ftps)
INFLUXDB_IMAGE=$(docker images -q ft_influxdb)
GRAFANA_IMAGE=$(docker images -q ft_grafana)
TELEGRAF_IMAGE=$(docker images -q ft_telegraf)

#Build containers

if [[ $INFLUXDB_IMAGE == "" ]];
	then
		cd $srcs/influxdb/ && ./build.sh
	else
		read -t 3 -n1 -p "Reload InfluxDB? [y/${cyan}N${blue}]${reset}" input
		echo ""
		if [[ $1 == "influxdb" ]] || [[ $1 == "nuke" ]] || ([ -n "$input" ] && [ "$input" == "y" ]);
			then
			kubectl delete -f influxdb-deployment.yaml
			docker image rm -f ft_influxdb
			cd $srcs/influxdb/ && ./build.sh
		fi
fi
cd $srcs/yaml/ && kubectl apply -f influxdb-deployment.yaml

if [[ $GRAFANA_IMAGE == "" ]];
	then
		cd $srcs/grafana/ && ./build.sh
	else
		read -t 3 -n1 -p "Reload Grafana? [y/${cyan}N${blue}]${reset}" input
		echo ""
		if [[ $1 == "grafana" ]] || [[ $1 == "nuke" ]] || ([ -n "$input" ] && [ "$input" != "n" ]);
			then
			cd $srcs/grafana/ && ./rebuild.sh
		fi
fi
cd $srcs/yaml/ && kubectl apply -f grafana-deployment.yaml

if [[ $NGINX_IMAGE == "" ]];
	then
		cd $srcs/nginx/ && ./build.sh
	else
		read -t 3 -n1 -p "Reload NGINX? [y/${cyan}N${blue}]${reset}" input
		echo ""
		if [[ $1 == "nginx" ]] || [[ $1 == "nuke" ]] || ([ -n "$input" ] && [ "$input" == "y" ]);
			then
			cd $srcs/nginx/ && ./rebuild.sh
		fi
fi
cd $srcs/yaml/ && kubectl apply -f nginx-deployment.yaml

if [[ $MYSQL_IMAGE == "" ]];
	then
		cd $srcs/mysql/ && ./build.sh
	else
		read -t 3 -n1 -p "Reload MySQL? [y/${cyan}N${blue}]${reset}" input
		echo ""
		if [[ $1 == "mysql" ]] || [[ $1 == "nuke" ]] || ([ -n "$input" ] && [ "$input" == "y" ]);
			then
			cd $srcs/mysql/ && ./rebuild.sh
		fi
fi
cd $srcs/yaml/ && kubectl apply -f mysql-deployment.yaml

if [[ $WORDPRESS_IMAGE == "" ]];
	then
		cd $srcs/wordpress/ && ./build.sh
	else
		read -t 3 -n1 -p "Reload Wordpress? [y/${cyan}N${blue}]${reset}" input
		echo ""
		if [[ $1 == "wordpress" ]] || [[ $1 == "nuke" ]] || ([ -n "$input" ] && [ "$input" == "y" ]);
			then
			cd $srcs/wordpress/ && ./rebuild.sh
		fi
fi
cd $srcs/yaml/ && kubectl apply -f wordpress-deployment.yaml

if [[ $PHPMYADMIN_IMAGE == "" ]];
	then
		cd $srcs/phpmyadmin/ && ./build.sh
	else
		read -t 3 -n1 -p "Reload PHPMyadmin? [Y/${cyan}N${blue}]${reset}" input
		echo ""
		if [[ $1 == "phpmyadmin" ]] || [[ $1 == "nuke" ]] || ([ -n "$input" ] && [ "$input" == "y" ]);
			then
			cd $srcs/phpmyadmin/ && ./rebuild.sh
		fi
fi
cd $srcs/yaml/ && kubectl apply -f phpmyadmin-deployment.yaml

if [[ $FTPS_IMAGE == "" ]];
	then
		cd $srcs/ftps/ && ./build.sh
	else
		read -t 3 -n1 -p "Reload FTPS? [y/${cyan}N${blue}]${reset}" input
		echo ""
		if [[ $1 == "ftps" ]] || [[ $1 == "nuke" ]] || ([ -n "$input" ] && [ "$input" == "y" ]);
			then
			cd $srcs/ftps/ && ./rebuild.sh
		fi
fi
cd $srcs/yaml/ && kubectl apply -f ftps-deployment.yaml

if [[ $FTPS_IMAGE == "" ]];
	then
		cd $srcs/telegraf/ && ./build.sh
	else
		read -t 3 -n1 -p "Reload Telegraf? [y/${cyan}N${blue}]${reset}" input
		echo ""
		if [[ $1 == "telegraf" ]] || [[ $1 == "nuke" ]] || ([ -n "$input" ] && [ "$input" == "y" ]);
			then
			cd $srcs/telegraf/ && ./rebuild.sh
		fi
fi
cd $srcs/yaml/ && kubectl apply -f telegraf-deployment.yaml
echo "para entrar en el pod: kubectl exec -it <podname> ./bin/sh"
echo "RUN minikube IP in your browser:"
cat /tmp/.minikube.ip
read -t 3 -n1 -p "[Y/${cyan}n${blue}]${reset}" input
		echo ""
		if [ -n "$input" ] && [ "$input" == "n" ];
			then
			echo "puedes abrir con el comando: open https://192.168.99.240"
			else
			open https://192.168.99.240
		fi
read -t 30 -n1 -p "Run 'minikube dashboard' for dashboard [y/${cyan}N${blue}]${reset}" input
		echo ""
		if [ -n "$input" ] && [ "$input" == "n" ];
			then
			echo "esperando 1 minuto para dar tiempo a ese MacCaca cargar todo"
			sleep 10
			echo "Cafe? Cigarrito? Addelante que es el momento, fatan 50 segundos"
			sleep 10
			echo "A que es lento? aun faltan 40 segudos"
			sleep 10
			echo "Ole, ya llegamos a la mitad! 30 segundos!"
			sleep 10
			echo "Ya nos queda poco juntos, mande recuerdos a la familia, 20 segundos."
			sleep 10
			echo "En 10 segundos me cambiaras por el dashboard de Minikube!"
			sleep 10
			echo "Adios mundo cruel..."
			minikube dashboard &
			else
			echo "puedes abrir con el comando: minikube dashboard &"
		fi