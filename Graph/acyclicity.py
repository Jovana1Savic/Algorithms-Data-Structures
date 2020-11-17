#Uses python3

import sys

def explore(v, adj, visited, recursion_stack):
    visited[v] = True
    recursion_stack.append(v)
    for w in adj[v]:
        if not visited[w]:
            if explore(w, adj, visited, recursion_stack) == 1:
                return 1
        elif w in recursion_stack:
            return 1
    recursion_stack.pop()
    return 0

# Check if graph has cycle. Return 1 if yes, else 0.
def acyclic(adj):
    
    visited = [False] * len(adj)
    for v in range(0, len(adj)):
        if not visited[v]:
            ret = explore(v, adj, visited, [])
            if ret == 1:
                return 1
    return 0
    
        

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
    print(acyclic(adj))
