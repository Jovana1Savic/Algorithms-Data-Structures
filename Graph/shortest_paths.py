#Uses python3

import sys
from queue import Queue

def relaxed_all_edges(adj, cost, dist):
    
    relaxed = False
    for u in range(len(adj)):
            for (i, v) in enumerate(adj[u]):
                if dist[v] > dist[u] + cost[u][i]:
                    dist[v] = dist[u] + cost[u][i]
                    relaxed = True
    return relaxed

def relaxed_edges_with_inf(adj, cost, dist):
    
    relaxed = False
    for u in range(len(adj)):
        for (i, v) in enumerate(adj[u]):
            if dist[v] > dist[u] + cost[u][i]:
                dist[v] = float("-inf")
                relaxed = True
                
    return relaxed
    

def shortest_paths(adj, cost, s):
    
    n = len(adj)
    dist = [float("inf") for _ in range(n)]
    
    dist[s] = 0
    
    for _ in range(n - 1):
        if not relaxed_all_edges(adj, cost, dist):
            return dist
        
         
    while relaxed_edges_with_inf(adj, cost, dist):
        pass
    
    return dist
      
    


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
    s = data[0]
    s -= 1
    dist = shortest_paths(adj, cost, s)
    for x in range(n):
        if dist[x] == float("inf"):
            print('*')
        elif dist[x] == float("-inf"):
            print('-')
        else:
            print(dist[x])

