import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from statistics import mean, median,variance,stdev

#filenames = ['data_time_kek3.txt','data_time_lbl.txt','data_time_lxplus.txt']
filenames = ['data_time_kek_nov_2.txt','data_time_lbl_nov.txt','data_time_lxplus_nov.txt']
#filenames = ['data_time_kek4.txt']
for filename in filenames:
    with open("result_nov/" + filename) as f:
        l = f.readlines()
    
    ntry = 30
    nfile = 5
    
    x = np.linspace(200,1000,nfile)
    y = []
    y_error = []
    #value = [0]*10
    
    for i in range(nfile):
        value = [0]*ntry
        for j in range(ntry):  
            value[j] = float(l[i+(nfile+1)*j])    
    
        m = mean(value)
        y.append(m)
        error = math.sqrt(variance(value)/(ntry-1))
        y_error.append(error) 
        
    print(y)
    print(y_error)

#a, b = np.polyfit(x, y, 1)
## フィッティング直線
#y2 = a * x + b
#
#fig=plt.figure()
#ax=fig.add_subplot()
#ax.scatter(x,y,alpha=0.5,color="Blue",linewidths="1")
#ax.plot(x, y2,color='black')
##ax.errorbar(x, y, yerr=y_error, fmt='ok')
#ax.text(0.1,a*0.1+b, 'y='+ str(round(a,4)) +'x+'+str(round(b,4)))
#plt.show()
