import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

with open("mes_individual_files_1214.txt") as f:
    ll = f.readlines()

k=0
kk=0
time_dict = {}
while k<len(ll):
    if ll[k] == "\n" or ll[k] == " \n" or "digital" in ll[k]:
        kk=0
    elif "std" in ll[k]:
        pass
    else:
        if kk not in time_dict:
            time_dict[kk] = []
        time_dict[kk].append(float(ll[k]))
    kk += 1   
    k += 1

mean_list = []
sigma_list = []
for i,v in time_dict.items():
    mean_list.append(mean(v))
    sigma_list.append(math.sqrt(variance(v)/(len(v)-1)))

with open("./confirm_file_upload_1214.txt") as f:
    l = f.readlines()

n=0
scan_time = []
this_scan_time = []
this_scan_sigma = []
while n<len(l):
    if l[n] == "\n" or l[n] == " \n":
        print("\hline")
        scan_time.append(str(round(sum(this_scan_time),4)) 
        + r"$ \pm $" 
        + str(round(math.sqrt(sum(this_scan_sigma)),4)))  
        this_scan_time = []
        this_scan_sigma = []
    else:
        l[n] = l[n].replace("_","$\_$").replace("\n","").split(" ")
        if len(l[n]) == 1:
            print(l[n][0],end="")
        else:
            s = ""
            for litem in l[n]:
                try:
                    s += " & " + str('{:.2g}'.format(round(float(litem)/1000,4)))
                except:
                    s += " & " + litem.replace("Error",r"{ \bf Error}")
            mean = mean_list.pop(0)
            sigma = sigma_list.pop(0)
            this_scan_time.append(mean)
            this_scan_sigma.append(pow(sigma,2))
            s += " & " + str('{:.2g}'.format(round(mean,4))) +" $\pm$ "+ str('{:.3g}'.format(round(sigma,4)))
            s += r" & \\"
            print(s)
    n+=1

print(scan_time)
