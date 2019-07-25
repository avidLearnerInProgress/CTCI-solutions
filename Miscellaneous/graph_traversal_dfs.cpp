//same for undirected graphs as well

//https://ide.geeksforgeeks.org/U6izoNIwXd
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

    void DFSUtil(int v, vector<bool>& visited){
        visited[v] = true;
        cout<<v<<" ";
        for(auto it=adj[v].begin(); it!=adj[v].end(); it++){
            if(!visited[*it])
            DFSUtil(*it, visited);
        }
    }

    void DFS(){
        vector<bool> visited(V, false);
        cout<<"DFS traversal:-\n";
        for(int i=0; i<V; i++){
            if(!visited[i])
                DFSUtil(i, visited);
        }
    }

    void DFSIterativeUtil(int v, vector<bool>& visited){
        stack<int> st;
        st.push(v);   
        while(!st.empty()){
            v = st.top();
            st.pop();
            if(!visited[v]){
                cout<<v<<" ";
                visited[v] = true;
            }

            for(auto it = adj[v].rbegin(); it != adj[v].rend(); it++){
                if(!visited[*it])
                    st.push(*it);
            }
        } 
    }

    void DFSIterative(){
        vector<bool> visited(V, false);
        cout<<"DFS iterative traversal:-\n";
        for(int i=0; i<V; i++){
            if(!visited[i])
                DFSIterativeUtil(i, visited);
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
    g.DFS();
    cout<<"\n";
    g.DFSIterative();
}