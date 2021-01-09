import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

def calRealTime(time):
    time = time.replace("s","").split("m")
    return 60 * float(time[0]) + float(time[1])

with open("./search_measurement_0109.txt") as f:
    l = f.readlines()

with open("./start_measurement_0109.txt") as f:
    l_start = f.readlines()

with open("./end_measurement_0109.txt") as f:
    l_end = f.readlines()

m=[]
error=[]

read_mean_list=[]
read_mean=0
for i in range(len(l_start)):
    if l_start[i] != "\n":
        read_mean_list.append(float(l_start[i].replace("\n","")))
        read_mean_list.append(float(l_end[i].replace("\n","")))
read_mean=mean(read_mean_list)
        

n=0
k=0
list_ = []
mes=0
m=[]
error=[]
while n<len(l):
    if l[n] == "\n":
        m.append(mean(list_))
        error.append(math.sqrt(variance(list_)/(len(list_)-1)))
        mes+=1
        if mes==5:
            for i in range(len(m)):       
                if not i==0: print(m[i],end=", ")
            
            print("")
            for i in range(len(error)):
                if not i==0: print(error[i],end=", ")
            print("")
            m=[]
            error=[]
            mes=0
        list_ = []
        k += 1
    elif "real" in l[n]:
        weight = (float(l_start[k].replace("\n",""))+float(l_end[k].replace("\n","")))/(2*read_mean)
        l[n] = l[n].replace("\n","").split("\t")
        time = calRealTime(l[n][1])
        list_.append(time/weight)
        k += 1
    else:
        pass
    n+=1


