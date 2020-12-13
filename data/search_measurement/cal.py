import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

#filenames = [
#'measure_JPS_keyword1.txt',
#'measure_JPS_keyword2.txt',
#'measure_JPS_keyword3.txt',
#'measure_JPS_keyword4.txt',
#'measure_JPS_keyword5.txt'
#]
filenames = [
"test2_1_thread_process1.txt",
"test2_2_thread_process1.txt",
"test2_3_thread_process1.txt",
"test2_4_thread_process1.txt"
]
m = []
error = [] 

for filename in filenames:
    with open(filename) as f:
        l = f.readlines()
    
    nline = 100
    value = [0]*nline
    
    for i in range(nline):
        value[i] = float(l[i])    
    
    m.append(mean(value))
    error.append(math.sqrt(variance(value)/(nline-1)))

print("{",end="")
for i in range(len(m)):       
    print(m[i],end=", ")
print("};")

print("{",end="")
for i in range(len(error)):
    print(error[i],end=", ")
print("};")


