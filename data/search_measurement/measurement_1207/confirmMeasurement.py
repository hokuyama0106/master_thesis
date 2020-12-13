import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

with open("search_measurement3.txt") as f:
    l = f.readlines()

with open("start_measurement3.txt") as f:
    l_start = f.readlines()

with open("end_measurement3.txt") as f:
    l_end = f.readlines()

m=[]
error=[]

n=0
list_start = []
list_end = []
mes=0
while n<len(l_start):
    if l_start[n] == "\n":
        print("Start:", end="")
        print(mean(list_start), end=" +- ")
        print(math.sqrt(variance(list_start)/(len(list_start)-1)))
        print("End:  ", end="")
        print(mean(list_end), end=" +- ")
        print(math.sqrt(variance(list_end)/(len(list_end)-1)))
        #m.append(mean(list_))
        #error.append(math.sqrt(variance(list_)/(len(list_)-1)))
        #mes+=1
        #if mes==4:
        #    for i in range(len(m)):       
        #        print(m[i],end=", ")
        #    
        #    print("")
        #    for i in range(len(error)):
        #        print(error[i],end=", ")
        #    print("")
        #    m=[]
        #    error=[]
        #    mes=0
        list_ = []
    else:
        l_start[n] = l_start[n].replace("\n","")
        list_start.append(float(l_start[n]))
        l_end[n] = l_end[n].replace("\n","")
        list_end.append(float(l_end[n]))
    n+=1


