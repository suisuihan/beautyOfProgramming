#coding: utf-8
import os
import time
import psutil
import affinity

affinity.set_process_affinity_mask(os.getpid(), 2L)
def makeUsage(level):
    while True:
        if psutil.cpu_percent(interval=None, percpu=True)[1] > level:
            time.sleep(0.005)

makeUsage(80)