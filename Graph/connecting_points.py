#Uses python3
import sys
import math
from heapq import heappush, heappop

           
def dist(x1, y1, x2, y2):
    return math.sqrt((x1 - x2)**2 + (y1-y2)**2)
    

def minimum_distance(x, y):
    
    n = len(x)
    
    visited = [False for _ in range(n)]
    cost = [float("inf") for _ in range(n)]
    
    cost[0] = 0
    heap = [(cost[0], 0)]
    
    while heap:
        c, v = heappop(heap)
        if visited[v]:
            continue
        visited[v] = True
        
        for u in range(n):
            if not visited[u] and cost[u] > dist(x[v], y[v], x[u], y[u]):
                cost[u] = dist(x[v], y[v], x[u], y[u])
                heappush(heap, (cost[u], u))
            
    return sum(cost)
        

if __name__ == '__main__':
    input = sys.stdin.read()
    #input = input()
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    print("{0:.9f}".format(minimum_distance(x, y)))
