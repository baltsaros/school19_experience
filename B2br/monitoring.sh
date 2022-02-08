lvm=$(lsblk | awk '/home/ {print $6}')
mem_u=$(free -m | awk '/Mem:/ {print $3}')
mem_t=$(free -m | awk '/Mem:/ {print $2}')
mem_p=$((($mem_u*100)/$mem_t))
disk_u=$(df -m --total | awk '/total/ {print $3}')
disk_ug=$(($disk_u/1000))
disk_t=$(df -m --total | awk '/total/ {print $2}')
disk_tg=$(($disk_t/1000))
disk_p=$(df -m --total | awk '/total/ {print $5}')
cpu=$(iostat -c | awk 'NR==4 {printf "%2.0f", $6}')
cpu_l=$((100 - $cpu))

wall -n << .
#Architecture: `uname -a`
#CPU physical : `lscpu -b -p=Core,Socket | grep -v '^#' | sort -u | wc -l`
#vCPU : `cat /proc/cpuinfo | grep processor | wc -l`
#Memory Usage: ${mem_u}/${mem_t}MB (${mem_p}%)
#Disk Usage: ${disk_u}/${disk_tg}Gb (${disk_p})
#CPU load: ${cpu_l}%
#Last boot: `who -b | awk '{print $3 " " $4}'`
#LVM use: `if [ $lvm = "lvm" ]
		then
			echo yes
		else 
			echo no
		fi`
#Connexions TCP :  `netstat -natp | awk '/ESTABLISHED/ {++cnt} END {printf "%d ESTABLISHED", cnt}'`
#User log: `who | wc -l`
#Network: `/sbin/ifconfig enp0s3 | awk '/inet / {printf "IP %s ", $2;} /ether/ {printf "(%s)", $2;}'`
#Sudo : `grep -c "COMMAND" /var/log/sudo/sudo.log | awk '{printf "%d cmd", $1}'`
.
