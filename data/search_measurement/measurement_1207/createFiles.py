import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

with open("search_measurement3.txt") as f:
    l = f.readlines()

with open("start_measurement.txt") as f:
    l_start = f.readlines()

with open("end_measurement.txt") as f:
    l_end = f.readlines()

m=[]
error=[]

n=0
list_ = []
mes=0
while n<len(l):
    if l[n] == "\n":
        #print(mean(list_), end=" ")
        #print(math.sqrt(variance(list_)/(len(list_)-1)))
        m.append(mean(list_))
        error.append(math.sqrt(variance(list_)/(len(list_)-1)))
        mes+=1
        if mes==4:
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
    else:
        l[n] = l[n].replace("\n","")
        list_.append(float(l[n]))
    n+=1


