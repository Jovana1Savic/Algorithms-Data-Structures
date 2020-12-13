#Uses python3

import sys
from queue import Queue


def find_sources(adj):
    
    n = len(adj)
    visited = [False for _ in range(n)]
    sources = []
    
    for v in range(len(adj)):
        
        if not visited[v]:
            
            sources.append(v)
            
            queue = Queue()
            queue.put(v)
            
            while not queue.empty():
                
                u = queue.get()
                for x in adj[u]:
                    if not visited[x]:
                        visited[x] = True
                        queue.put(x)
                        
    return sources
            

def relaxed_edges(adj, cost, dist):
    
    relaxed = False
    
    for v in range(len(adj)):
        for (i,u) in enumerate(adj[v]):
            if dist[u] > dist[v] + cost[v][i]:
                dist[u] = dist[v] + cost[v][i]
                relaxed = True
                
    return relaxed


def negative_cycle_from_source(adj, cost, source):
    
    n = len(adj)
    dist = [float("inf") for _ in range(n)]
    dist[source] = 0
    
    for _ in range(n - 1):
        if not relaxed_edges(adj, cost, dist):
            return 0
        
    if relaxed_edges(adj, cost, dist):
        return 1
    
    return 0
       

def negative_cycle(adj, cost):
    
    sources = find_sources(adj)
    
    for source in sources:
        if negative_cycle_from_source(adj, cost, source):
            return 1
    
    return 0


if __name__ == '__main__':
    input = sys.stdin.read()
    #input = input()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(zip(data[0:(3 * m):3], data[1:(3 * m):3]), data[2:(3 * m):3]))
    data = data[3 * m:]
    adj = [[] for _ in range(n)]
    cost = [[] for _ in range(n)]
    for ((a, b), w) in edges:
        adj[a - 1].append(b - 1)
        cost[a - 1].append(w)
    print(negative_cycle(adj, cost))
