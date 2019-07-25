//same for undirected graphs as well
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V; //no of vertices
    vector<int> *adj; //adjacency list
    public:
    Graph(int v){
        V = v;
        adj = new vector<int>[V]; //vector of arrays!
    }
    //add w to array u within vector adj
    void addEdge(int u, int w){
        adj[u].push_back(w);
    }

    void BFSIterativeUtil(int v, vector<bool>& visited){
        list<int> que;
        que.push_back(v);   
        while(!qu.empty()){
            v = qu.front();
            cout<<v<<" ";
            qu.pop_front();
            
            for(auto it = adj[v].rbegin(); it != adj[v].rend(); it++){
                if(!visited[*it])
                    qu.push_back(*it);
            }
        } 
    }

    void BFSIterative(){
        vector<bool> visited(V, false);
        cout<<"BFS iterative traversal:-\n";
        for(int i=0; i<V; i++){
            if(!visited[i])
                BFSIterativeUtil(i, visited);
        }
    }
};


int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS();
    cout<<"\n";
    g.BFSIterative();
}