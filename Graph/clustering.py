#Uses python3
import sys
import math

class DisjointSet:
    def __init__(self, N):
        self.parent = [i for i in range(N)]
        self.rank = [0 for i in range(N)]
        
    def Find(self, i):
        if i != self.parent[i]:
            self.parent[i] = self.Find(self.parent[i])
        return self.parent[i]
    
    def Union(self, i, j):
        i_id = self.Find(i)
        j_id = self.Find(j)
        
        if i_id == j_id:
            return
        
        if self.rank[i_id] > self.rank[j_id]:
            self.parent[j_id] = i_id
        else:
            self.parent[i_id] = j_id
            if self.rank[i_id] == self.rank[j_id]:
                self.rank[j_id] += 1
                
    def inSameSet(self, i, j):
        return self.Find(i) == self.Find(j)
        

def dist(x1, y1, x2, y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)


def nextEdge(forest, edges, last_edge_ind):
    
    for i in range(last_edge_ind + 1, len(edges)):
        if not forest.inSameSet(edges[i][0], edges[i][1]):
            forest.Union(edges[i][0], edges[i][1])
            return i
    
def clustering(x, y, k):

    n = len(x)
    edges = []
    for i in range(n):
        for j in range(i + 1, n):
            edges.append((i, j, dist(x[i], y[i], x[j], y[j])))
            
    edges.sort(key=lambda x : x[2])
    
    forest = DisjointSet(n)
    last_edge_ind = -1
    
    for i in range(0, n - k):
        last_edge_ind = nextEdge(forest, edges, last_edge_ind)
        
    d_ind = nextEdge(forest, edges, last_edge_ind)
    return edges[d_ind][2]
    
    

if __name__ == '__main__':
    input = sys.stdin.read()
    #input = input()
    data = list(map(int, input.split()))
    n = data[0]
    data = data[1:]
    x = data[0:2 * n:2]
    y = data[1:2 * n:2]
    data = data[2 * n:]
    k = data[0]
    print("{0:.9f}".format(clustering(x, y, k)))
