#https://ide.geeksforgeeks.org/kVYI9EqC5t
from collections import defaultdict, deque

class Graph:
    def __init__(self, v):
        self.vertices = v
        self.adjacent_edges = defaultdict(list)
    
    def add_edge(self, a, b): #this acts as a list of list or vec of vec
        self.adjacent_edges[a].append(b)
    
    def is_reachable(self, src, dest):
        if src == dest: #basecase
            return True
        self.traversed = self.vertices * [False]
        self.traversed[src] = True
        queue = deque()
        queue.append(src) #on right --> rear
        while queue:
            current = queue.popleft() #on left --> front
            if current == dest: #this is helpful, no need to flood the adjacency list with neighbours if current is dest
                return True
            for node in self.adjacent_edges[current]:
                if node == dest: #without this we unnecessarily keep on inserting nodes in queue and then check for existence of path at dequeue
                    return True
                if self.traversed[node] == False:
                    self.traversed[node] = True
                    queue.append(node)
        return False

if __name__ == '__main__':
    g = Graph(4)
    g.add_edge(0, 1) 
    g.add_edge(0, 2) 
    g.add_edge(1, 2) 
    g.add_edge(2, 0) 
    g.add_edge(2, 3)
    g.add_edge(3, 3)
    u, v = 1, 3
    if g.is_reachable(u, v):
        print("There is a path from %d to %d" % (u,v)) 
    else : 
        print("There is no path from %d to %d" % (u,v)) 