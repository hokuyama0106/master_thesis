import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from datetime import datetime as dt
from statistics import mean, median,variance,stdev


def calUnixTime(time):
    time = time.split(" ")
    tstr = "2021-01-" + time[2] + " " + time[3]
    tdatetime = dt.strptime(tstr, '%Y-%m-%d %H:%M:%S')
    return tdatetime.timestamp()

with open("pd_connection_time_kek.txt") as f:
    l = f.readlines()

with open("pd_connection_time_lbl.txt") as f:
    ll = f.readlines()

time=""
kek_num_list = []
lbl_num_list = []
time_list = []
kek_mean_list = []
kek_sigma_list = []
lbl_mean_list = []
lbl_sigma_list = []
n=0
while n<len(l):
    if l[n] == ' \n' or l[n] == '\n':
        time_list.append(calUnixTime(time))
        kek_mean_list.append(mean(kek_num_list))
        kek_sigma_list.append(math.sqrt(variance(kek_num_list)/(len(kek_num_list)-1)))
        lbl_mean_list.append(mean(lbl_num_list))
        lbl_sigma_list.append(math.sqrt(variance(lbl_num_list)/(len(lbl_num_list)-1)))      
        kek_num_list = []
        lbl_num_list = []
        time = ""
    elif "Jan" in l[n]:
        time=l[n].replace("\n","")
    else:
        kek_num_list.append(float(l[n]))
        lbl_num_list.append(float(ll[n]))
    n+=1

for i, time in enumerate(time_list):
    print(time,end=" ")
    #print('{:.3g}'.format(round(kek_mean_list[i],4)),end=" ")
    #print('{:.3g}'.format(round(kek_sigma_list[i],4)),end=" ")
    print('{:.3g}'.format(round(lbl_mean_list[i],4)),end=" ")
    print('{:.3g}'.format(round(lbl_sigma_list[i],4)),end=" ")
    print("")









