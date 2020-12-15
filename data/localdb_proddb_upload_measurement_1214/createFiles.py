import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev


def calRealTime(time):
    time = time.replace("s","").split("m")
    return 60 * float(time[0]) + float(time[1])

with open("mes_upload_total_1214.txt") as f:
    l = f.readlines()

with open("mes_initial_process_1214.txt") as f:
    ll = f.readlines()

initial = []
k=0
while k<len(ll):
    initial.append(float(ll[k]))
    k+=1
    

n=0
num=0
dict_={}
real_list = []
while n<len(l):
    if l[n] == ' \n' or l[n] == '\n':
        num=0
    else:
        l[n] = l[n].split("\t")
        if len(l[n]) == 1:
            l[n][0] = l[n][0].replace("\n","")
            if num not in dict_:
                dict_[num] = []
            dict_[num].append(float(l[n][0]))
        elif "real" in l[n]:
            real_list.append(calRealTime(l[n][1].replace("\n","")))
        num+=1
    n+=1

odd_list = []
even_list = []
for i,v in dict_.items():
    if i == 0 or i == 1 or i == 12:
        print(mean(v),end=" +- ")
        print(math.sqrt(variance(v)/(len(v)-1)))
    else:
        if i%2 == 0: even_list += v
        else: odd_list += v

print(sum(initial)/20,end=" +- ")
print(math.sqrt(variance(initial)/19))
print(sum(even_list)/20,end=" +- ")
print(math.sqrt(variance(even_list)/19))
print(sum(odd_list)/20,end=" +- ")
print(math.sqrt(variance(odd_list)/19))

print(mean(real_list),end=" +- ")
print(math.sqrt(variance(real_list)/(len(real_list)-1)))
