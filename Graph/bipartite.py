#Uses python3

import sys
from queue import Queue

def bipartite(adj):
    
    colors = [-1] * len(adj)
    
    for i in range(len(adj)):
        
        if colors[i] == -1:
            
            # do bfs from here           
            q = Queue()
            q.put(i)
            colors[i] = 0
            
            while not q.empty():
                
                u = q.get()
                for v in adj[u]:
                    if colors[v] == -1:
                        colors[v] = 1 - colors[u]
                        q.put(v)
                    elif colors[v] == colors[u]:
                        return 0
    
    return 1

if __name__ == '__main__':
    input = sys.stdin.read()
    #input = input()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    adj = [[] for _ in range(n)]
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(bipartite(adj))
