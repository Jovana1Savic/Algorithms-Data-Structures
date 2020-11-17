#Uses python3

import sys

def explore(adj, components, x, cc):
    components[x] = cc
    for v in adj[x]:
        if components[v] == -1:
            explore(adj, components, v, cc)

def number_of_components(adj):
    n = len(adj)
    components = [-1]*n
    cc = 1
    for x in range(n):
        if components[x] == -1:
            explore(adj, components, x, cc)
            cc += 1
    
    return max(components)
    

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
    print(number_of_components(adj))
