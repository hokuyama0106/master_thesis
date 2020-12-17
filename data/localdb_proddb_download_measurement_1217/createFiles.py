import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev


def calRealTime(time):
    time = time.replace("s","").split("m")
    return 60 * float(time[0]) + float(time[1])

with open("mes_download_1217.txt") as f:
    l = f.readlines()

n=0
num=0
dict_={}
real_list = []
while n<len(l):
    if l[n] == ' \n' or l[n] == '\n':
        num=0
    else:
        if not num == 0:
            if num not in dict_:
                dict_[num] = []
            dict_[num].append(float(l[n]))
        num+=1
    n+=1

total=0
sigma=0
for i,v in dict_.items():
    if i != 9:
        total+=mean(v)
        sigma+=variance(v)/(len(v)-1)
    print('{:.3g}'.format(mean(v)),end=" +- ")
    #print('{:.3g}'.format(math.sqrt(variance(v)/(len(v)-1))))
    print('{:.3g}'.format(variance(v)/(len(v)-1)))


print(total,end=" +- ")
print(sigma)
