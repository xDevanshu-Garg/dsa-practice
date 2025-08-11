#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<int> &vis, vector<vector<int>>& adj, stack<int>& s) {
    vis[node] = true;
    
    for(int nei: adj[node]) {
        if(!vis[nei])
            topoSort(nei, vis, adj, s);
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //Making adj list
    vector<vector<int>> adj(v);
    for(auto edge: edges)
        adj[edge[0]].push_back(edge[1]);

    stack<int> s;
    vector<int> vis(v);
    for(int i = 0; i < v; i++) {
        if(!vis[i])
            topoSort(i, vis, adj, s);
    }

    //Store the ans in a vector and reverse it
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}