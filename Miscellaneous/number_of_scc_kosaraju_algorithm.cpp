#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

void topological_sort(vector<vector<int> > &adj, vector<bool> &used, stack<int> &s, int x) {
    //write your code here
    used[x] = true;
    for(auto it = adj[x].begin(); it != adj[x].end(); it++){
        if(!used[*it]){
            used[*it] = true;
            topological_sort(adj, used, s, *it);
        }
    }
    // All vertices reachable from x are processed by now, push x to Stack
    s.push(x);
}
//reverse edges
vector<vector<int> > transpose_graph(vector<vector<int> > adj){
    vector<vector<int> > rEdges(adj.size(), vector<int>());

    for(int i = 0; i < adj.size(); i++){
        for(int j = 0; j < adj[i].size(); j++){
            rEdges[adj[i][j]].push_back(i);
        }
    }
    return rEdges;
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
    int result = 0;
    //write your code here
    stack<int> topo;
    vector<bool> visited(adj.size(), false);
    for(int i = 0; i < adj.size(); i++){
        if(!visited[i])
            topological_sort(adj, visited, topo, i);
    }

    vector<vector<int> > rGraph = transpose_graph(adj);
    visited.clear();
    visited.assign(rGraph.size(), false);
    visited.shrink_to_fit();
    
    while(!topo.empty()){
        int curr = topo.top();
        topo.pop();
        if(!visited[curr]){
            stack<int> elementStack;
            topological_sort(rGraph, visited, elementStack, curr);
            result++;
        }
    }
    return result;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << number_of_strongly_connected_components(adj);
}
