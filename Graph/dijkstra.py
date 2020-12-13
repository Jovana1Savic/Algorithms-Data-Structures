#Uses python3

import sys
from heapq import heappush, heappop


            
def distance(adj, cost, s, t):
    
    n = len(adj)
    max_cost = float("inf")
    dist = [max_cost for _ in range(n)]
    dist[s] = 0    
    minHeap = [(dist[s], s)]
    visited = [False for _ in range(n)]

    
    while minHeap:
        d, u = heappop(minHeap)
        if visited[u]:
            continue
        visited[u] = True
        if d >= max_cost:
            break
        if u == t:
            return d
        for (i, v) in enumerate(adj[u]):
            if dist[v] > dist[u] + cost[u][i]:
                dist[v] = dist[u] + cost[u][i]
                heappush(minHeap, (dist[v], v))
                
    if dist[t] >= max_cost:
        return -1
    return dist[t]


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
    s, t = data[0] - 1, data[1] - 1
    print(distance(adj, cost, s, t))
