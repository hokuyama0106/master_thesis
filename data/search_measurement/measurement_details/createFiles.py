import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

with open("./data/search_measurement_detail.txt") as f:
    l = f.readlines()

with open("./data/start_measurement_detail.txt") as f:
    l_start = f.readlines()

with open("./data/end_measurement_detail.txt") as f:
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
list_ = []
mes=0
while n<len(l):
    weight = (float(l_start[n].replace("\n",""))+float(l_end[n].replace("\n","")))/(2*read_mean)
    l[n] = l[n].replace("\n","")
    list_.append(float(l[n])/weight)
    n+=1

#print(mean(list_), end=" ")
#print(math.sqrt(variance(list_)/(len(list_)-1)))
m.append(mean(list_))
error.append(math.sqrt(variance(list_)/(len(list_)-1)))
mes+=1
for i in range(len(m)):       
    print(m[i],end=", ")

print("")
for i in range(len(error)):
    print(error[i],end=", ")
print("")
m=[]
error=[]
mes=0
list_ = []

