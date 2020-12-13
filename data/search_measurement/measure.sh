#!/bin/bash
for ((i=0 ; i<100 ; i++))
do
curl "http://127.0.0.1:5000/localdb/scan?keywords=okuyama&match=partial" -o /dev/null -w "%{time_total}\n" 2> /dev/null -s
#PID=`ps -A | grep -m1 app.py | awk '{ print $1 }'i`
#echo "$PID"
done
