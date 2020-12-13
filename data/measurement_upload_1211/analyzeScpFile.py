import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

with open("./data/mes_send_scp_1212.txt") as f:
    l = f.readlines()


m=[]
error=[]
n=0
list_ = []
while n<len(l):
    if l[n] == "\n":
        m.append(mean(list_))
        error.append(math.sqrt(variance(list_)/(len(list_)-1)))
        list_ = []
    else:
        if "real" in l[n]:
            l[n] = l[n].replace("\n","").split(" ")[1]
            list_.append(float(l[n]))
    n+=1

for m_v in m: print(m_v,end=",") 
print("")
for error_v in error: print(error_v,end=",") 
print("")