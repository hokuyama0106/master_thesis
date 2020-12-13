import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev


filenames = [
"test2_1_thread_process1.txt",
"test2_2_thread_process1.txt",
"test2_3_thread_process1.txt",
"test2_4_thread_process1.txt",
]
m = []
error = [] 

for i,filename in enumerate(filenames):

    with open("test2.txt") as f:
        l = f.readlines()

    nline = 106
    
    for j in range(nline):
        if 4 < j and not j == 105:
            with open(filename, mode='a') as f:
                f.write(l[j+nline*i])
    
