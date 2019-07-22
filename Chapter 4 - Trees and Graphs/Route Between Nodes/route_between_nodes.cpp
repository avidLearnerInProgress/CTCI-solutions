//https://ide.geeksforgeeks.org/zqGYtS5YWg
#include<bits/stdc++.h>
using namespace std;

//directed graph
class Graph{
    int Vertices;
    list<int> *Edges;
    public:
    //initialisation lists dont work in assigning memory of size V to vector pointer
    //Graph(int V) : Vertices(V), Edges(new vector<int>(V)){}
    Graph(int V){
        Vertices = V;
        Edges = new list<int>[V];
    }
    void add_edge(int a, int b){ //Add b to element a's list in vector  v
        Edges[a].push_back(b);
        //for undirected Graph
        //Edges[b].push_back(a);
    }
    
    bool is_reachable(int src, int dest){
        if(src == dest)
            return true; //basecase
        
        //else
        vector<bool> traversed(Vertices, false);
        list<int> qu; //myqueue
        
        traversed[src] = true;
        qu.push_back(src);
        
        while(!qu.empty()){
            int top = qu.front();
            qu.pop_front();
            for(auto it=Edges[top].begin(); it!=Edges[top].end(); it++){
                if(*it == dest)
                    return true;
                if(!traversed[*it]){
                    traversed[*it] = true;
                    qu.push_back(*it);
                }
            }
        }
        return false;
    }
    
};


int main(){
    Graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 
    int u = 1, v = 3; 
    if(g.is_reachable(u, v)) 
        cout<< "There is a path from " << u << " to " << v; 
    else cout<< "There is no path from " << u << " to " << v; 
  
}