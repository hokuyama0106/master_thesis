#./bin/bash

data[0]="data/1k"
data[1]="data/3k"
data[2]="data/10k"
data[3]="data/30k"
data[4]="data/100k"
data[5]="data/300k"
data[6]="data/1m"
data[7]="data/3m"
data[8]="data/10m"
data[9]="data/30m"
data[10]="data/100m"

for datasize in "${data[@]}"
   do
   for ((i=0 ; i<10 ; i++))
     do
     (time -p  sshpass -p "Yoku0106!" scp ${datasize} hokuyama@lxplus.cern.ch:~/measurement/data) >> mes_scp_kekcern_1213.txt 2>&1
     done
   echo "" >> mes_scp_kekcern_1213.txt
   done

