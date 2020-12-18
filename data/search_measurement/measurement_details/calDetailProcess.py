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

with open("./data/measurement_details_1210.txt") as f:
    l_detail = f.readlines()

num = 0
for i in range(len(l_detail)):
    if l_detail[i] != "\n":
        ll = l_detail[i].replace("\n","").split(":")
        if ll[0] == "dominated":
            l_detail[i] = ll[0] + str(num) + ":" + ll[1]
            num+=1
    else:
        num = 0
            
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
dict_ = {}
mes=0
while n<len(l):
    total=0
    if l[n]!="\n":
        weight = (float(l_start[n].replace("\n",""))+float(l_end[n].replace("\n","")))/(2*read_mean)
        list_.append(float(l[n])/weight)
        k=0
        while l_detail[n*10+k] != "\n": 
           lll = l_detail[n*10+k].replace("\n","").split(":") 
           if not lll[0] in dict_:
               dict_[lll[0]] = []
           dict_[lll[0]].append(float(lll[1])/weight)       
           if "process" in lll[0]:
                total+=float(lll[1])
           k+=1 
    n+=1

print(mean(list_), end=" ")
print(math.sqrt(variance(list_)/(len(list_)-1)))
m.append(mean(list_))
error.append(math.sqrt(variance(list_)/(len(list_)-1)))
mes+=1
for i in range(len(m)):       
    print(m[i],end=", ")

print("")
for i in range(len(error)):
    print(error[i],end=", ")
print("")

total=0
for i,v in dict_.items():
    print(i+":",end=" ")
    print(sum(v)/20, end=" +- ")
    print(math.sqrt(variance(v)/(20-1)))
print(total)
