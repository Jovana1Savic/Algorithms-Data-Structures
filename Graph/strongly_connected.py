#Uses python3

import sys

sys.setrecursionlimit(200000)

def reverse_graph(adj):
    
    rev_adj = [[] for _ in range(len(adj))]
    
    for i in range(len(adj)):
        for j in adj[i]:
            rev_adj[j].append(i)
    
    return rev_adj

def dfs_post(x, adj, visited, postorder):
    
    visited[x] = True
    for v in adj[x]:
        if not visited[v]:
            dfs_post(v, adj, visited, postorder)
    
    postorder.append(x)

def post_order(adj):
    
    visited = [False]*len(adj)
    postorder = []
    for x in range(len(adj)):
        if not visited[x]:
            dfs_post(x, adj, visited, postorder)
    
    return postorder
    
def dfs_cc(x, adj, visited, cc):
    
    visited[x] = cc
    for v in adj[x]:
        if visited[v] == -1:
            dfs_cc(v, adj, visited, cc)
    
    
def number_of_strongly_connected_components(adj):
    
    rev_graph = reverse_graph(adj)
    postorder = post_order(rev_graph)
    visited = [-1]*len(adj)
    cc = 0
    
    for v in reversed(postorder):
        if visited[v] == -1:
            cc += 1
            dfs_cc(v, adj, visited, cc)
            
    return cc

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
    print(number_of_strongly_connected_components(adj))
