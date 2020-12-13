#!/usr/bin/env python3
import sys
import itkdb
import os
import time

data_list = [
#'1k',
#'3k',
#'10k',
#'30k',
#'100k',
#'300k',
#'1m',
#'4m'
'100m'
]
lab = "LOCAL"

pd_client = itkdb.Client()
testRun = '5fd31ec0a9fef6000afbfe7a'

for i,dataname in enumerate(data_list):

    for j in range(10):
        with open('files/'+dataname, "r") as f:
        #with open('data/1b.txt', "rb") as f:
            data = f
            filename = dataname
            filetype = filename.split('.')[-1]
            page_attachment = {'data': (filename, data, filetype)}
            os.system('./connect_pd_web.sh >> start_mes_' + lab + '.txt')
            start = time.time()
            new_test_attachment = pd_client.post('createTestRunAttachment', data=dict(testRun=testRun, type='file'), files=page_attachment)
            end = time.time()
            stime = end-start
            os.system('./connect_pd_web.sh >> end_mes_' + lab + '.txt')
            print(stime)
    os.system('echo "" >> start_mes_' + lab + '.txt')
    os.system('echo "" >> end_mes_' + lab + '.txt')
    print(" ")





        

