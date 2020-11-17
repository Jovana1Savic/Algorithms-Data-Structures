#Uses python3

import sys

def dfs(adj, visited, order, x):
    visited[x] = True
    for v in adj[x]:
        if not visited[v]:
            dfs(adj, visited, order, v)
    order.append(x)


def toposort(adj):
    visited = [False] * len(adj)
    order = []
    
    for v in range(len(adj)):
        if not visited[v]:
            dfs(adj, visited, order, v)
      
    order.reverse()
    return order

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
    order = toposort(adj)
    for x in order:
        print(x + 1, end=' ')

