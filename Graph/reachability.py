#Uses python3

import sys

def explore(adj, x, visited):
    visited[x] = True
    for v in adj[x]:
        if not visited[v]:
            explore(adj, v, visited)

def reach(adj, x, y):
    n = len(adj)
    visited = [False]*n
    explore(adj, x, visited)
    if visited[y]:
        return 1
    return 0

if __name__ == '__main__':
    input = sys.stdin.read()
    #input = input()
    data = list(map(int, input.split()))
    n, m = data[0:2]
    data = data[2:]
    edges = list(zip(data[0:(2 * m):2], data[1:(2 * m):2]))
    x, y = data[2 * m:]
    adj = [[] for _ in range(n)]
    x, y = x - 1, y - 1
    for (a, b) in edges:
        adj[a - 1].append(b - 1)
        adj[b - 1].append(a - 1)
    print(reach(adj, x, y))
