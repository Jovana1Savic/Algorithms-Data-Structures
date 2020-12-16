# -*- coding: utf-8 -*-
"""
Created on Wed Dec 16 13:20:47 2020

@author: Jovana
"""
from heapq import heappush, heappop

def loadBalancing(jobs, m):
    
    load = [0 for _ in range(m)]
    heap = [(0, i) for i in range(m)]
    
    for job in jobs:
        
        cur_load, machine = heappop(heap)
        load[machine] += job
        heappush(heap, (load[machine], machine))
        
    return max(load)

def readInputFromFile(filename):
    
    file = open(filename, 'r')
    line = file.readline()
    
    [m, n] = [int(x) for x in line.rstrip().split()]
    
    jobs = [0 for _ in range(n)]
    
    for i in range(n):
        line = file.readline()
        if not line:
            print("Not enough jobs!")
            break
        jobs[i] = int(line.rstrip())
    
    file.close()
    
    return jobs, m
        
if __name__ == '__main__':
    
    res = ""
    
    for i in range(1, 4):
        filename = "inputJobs" + str(i) + ".txt"
        jobs, m = readInputFromFile(filename)
        res += str(loadBalancing(jobs, m)) +"  "
        
    output = open("output.txt", "w")
    output.write(res)
    output.close()
        
        
