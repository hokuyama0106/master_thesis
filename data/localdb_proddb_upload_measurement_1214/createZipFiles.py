import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev


def calRealTime(time):
    time = time.replace("s","").split("m")
    return 60 * float(time[0]) + float(time[1])

with open("mes_upload_zip_total_1214.txt") as f:
    l = f.readlines()

n=0
dict_={}
real_list = []
while n<len(l):
    if l[n] == ' \n' or l[n] == '\n':
        pass
    elif "real" in l[n]:
        real_list.append(calRealTime(l[n].split("\t")[1].replace("\n","")))
    else:
        l[n] = l[n].split(" ")
        if len(l[n]) == 4:
            l[n][3] = l[n][3].replace("\n","")
            if l[n][0] not in dict_:
                dict_[l[n][0]] = {"point":[], "status":l[n][2], "size":l[n][1]}
            dict_[l[n][0]]["point"].append(float(l[n][3]))
    n+=1

for i,v in dict_.items():
    #print(i.replace("_","$\_$"), end=" & ")
    #print(v["status"],end=" & ")
    #print('{:.3g}'.format(float(v["size"])/1000),end=" & ")
    print('{:.3g}'.format(mean(v["point"])),end=" $\pm$ ")
    #print('{:.3g}'.format(math.sqrt(variance(v["point"])/(len(v["point"])-1))))
    print('{:.3g}'.format(variance(v["point"])/(len(v["point"])-1)))

print('{:.3g}'.format(mean(real_list)),end=" +- ")
print('{:.3g}'.format(math.sqrt(variance(real_list)/(len(real_list)-1))))
