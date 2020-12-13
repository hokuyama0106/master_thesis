#!/usr/bin/env python3
import sys
import itkdb
import time

testRun = '5fd31ec0a9fef6000afbfe7a'
pd_client = itkdb.Client()
docs = pd_client.get('getTestRun', json={"testRun":testRun})
for attachment in docs["attachments"]:
    docs = pd_client.post('deleteTestRunAttachment', json={"testRun":testRun, "code":attachment["code"]})



