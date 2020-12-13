import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

#filenames = ['average_kek.txt','average_lbl.txt','average_lxplus.txt']
filenames = ['getModuleTime_kek.txt','getModuleTime_lbl.txt',"getModuleTime_lxplus.txt"]
for filename in filenames:
    with open(filename) as f:
        l = f.readlines()
    
    ntry = 30
    
    x = np.linspace(1,11,6)
    y = []
    y_error = []
    #value = [0]*10
    value = [0]*ntry
    for i in range(ntry):
        value[i] = float(l[i])    
    
    m = mean(value)
    y.append(m)
    error = math.sqrt(variance(value)/(ntry-1))
    y_error.append(error) 
        
    print(y)
    print(y_error)
    
