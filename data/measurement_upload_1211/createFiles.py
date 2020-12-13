import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

lab = "lbl"
with open("./data/mes_upload_" + lab + "_1211.txt") as f:
    l = f.readlines()

with open("./data/start_mes_" + lab + ".txt") as f:
    l_start = f.readlines()

with open("./data/end_mes_" + lab + ".txt") as f:
    l_end = f.readlines()

read_mean_list=[]
read_mean=0
for i in range(len(l_start)):
    if l_start[i] != "\n" and l_start[i] != " \n":
        read_mean_list.append(float(l_start[i].replace("\n","")))
        read_mean_list.append(float(l_end[i].replace("\n","")))
read_mean=mean(read_mean_list)
 
m=[]
error=[]
n=0
list_ = []
while n<len(l):
    if l[n] == ' \n' or l[n] == '\n':
        m.append(mean(list_))
        error.append(math.sqrt(variance(list_)/(len(list_)-1)))
        list_ = []
    else:
        weight = (float(l_start[n].replace("\n",""))+float(l_end[n].replace("\n","")))/(2*read_mean)
        l[n] = l[n].replace("\n","")
        list_.append(float(l[n])/weight)
    n+=1

for m_v in m: print(m_v,end=",") 
print("")
for error_v in error: print(error_v,end=",") 
print("")
