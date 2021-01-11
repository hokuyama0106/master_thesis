import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

with open("./confirm_file_upload_1214.txt") as f:
    l = f.readlines()

n=0
scan_time = []
this_scan_time = []
this_scan_sigma = []
total = 0
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
            total += float(l[n][2])
    n+=1

print(scan_time)
print(total)
