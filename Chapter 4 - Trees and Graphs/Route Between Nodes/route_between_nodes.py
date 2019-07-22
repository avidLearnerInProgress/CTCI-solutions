#https://ide.geeksforgeeks.org/adoe7k3KIp
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
    
    def print_path(self, path):
        for i in range(len(path)):
            print(path[i], end = ' -> ')
        print()
    
    def isnot_visited(self, vertex, path):
            for i in range(len(path)):
                if path[i] == vertex:
                    return 0
            return 1
            
    def possible_path(self, src, dest):
        if src == dest:
            return (str(src) + '->' + str(dest))

        found = False #path switch
        path_nodes = defaultdict(list)
        queue = deque()
        queue.append(src) #on right --> rear
        while queue:
            current = queue.popleft() #on left --> front
            if current == dest: 
                found = True
                break
            for node in self.adjacent_edges[current]:
                path_nodes[current] = node
                queue.append(node)
        if found:
            pq = deque()
            curr_path = []
            pq.append(path_nodes[src])
            while pq:
                curr = pq.popleft()
                if path_nodes[curr] != []:
                    curr_path.append(curr)
                    if dest in path_nodes:
                        break
                    pq.append(path_nodes[curr])
            curr_path.insert(0, src)
            curr_path.insert(len(curr_path) + 1, dest)
            print(curr_path)

            '''
            curr_path.append(src)
            path_queue.append(curr_path)
            
            while path_queue:
                curr_path = path_queue.popleft() #returns a list
                print(curr_path)
                end_node = curr_path[len(curr_path) - 1]
                print(end_node)
                
                if end_node == dest:
                    self.print_path(curr_path) #print current path aka list in queue
                for node in self.adjacent_edges[end_node]: #iterate over all neighbours of end_node
                    if self.isnot_visited(node, curr_path):
                        newls = list()
                        newls.append(node)
                        path_queue.append(newls)
            '''

if __name__ == '__main__':
    g = Graph(4)
    g.add_edge(0, 3) 
    g.add_edge(0, 1) 
    g.add_edge(0, 2) 
    g.add_edge(1, 3) 
    g.add_edge(2, 0)
    g.add_edge(2, 1)
    u, v = 2, 3
    if g.is_reachable(u, v):
        print("There is a path from %d to %d" % (u,v)) 
    else : 
        print("There is no path from %d to %d" % (u,v)) 
    g.possible_path(u, v)