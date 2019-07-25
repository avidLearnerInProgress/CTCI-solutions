#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &adj, vector<int> &used, stack<int> &s, int x) {
    //write your code here
    used[x] = true;

    for(auto it = adj[x].begin(); it != adj[x].end(); it++){
        if(!used[*it]){
            dfs(adj, used, s, *it);
        }
    }
    s.push(x);
}     

vector<int> toposort(vector<vector<int> > adj) {
    vector<int> used(adj.size(), 0);
    vector<int> order;
    //write your code here
    stack<int> topological;
    
    for(int i = 0; i < adj.size(); i++){
        if(!used[i])
            dfs(adj, used, topological, i);
    }
    while(!topological.empty()){
        order.push_back(topological.top());
        topological.pop();
    }
    return order;
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
    vector<int> order = toposort(adj);
    for (size_t i = 0; i < order.size(); i++) {
        std::cout << order[i] + 1 << " ";
    }
}
