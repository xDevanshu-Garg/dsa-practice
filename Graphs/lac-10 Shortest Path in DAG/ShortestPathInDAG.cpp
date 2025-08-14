#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897?leftPanelTabValue=SUBMISSION
void topoDFS(int node, vector<vector<pair<int, int>>>& adj, stack<int>& s, vector<int>& vis) {
    vis[node] = 1;
    
    for(auto nei: adj[node]) {
        if(!vis[nei.first])
            topoDFS(nei.first, adj, s, vis);
    }
    s.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    //Here we need to create distance vector for 0

    // Step1: Make adj list
    // 0 -> {{1,2}, {vertex, dist}} 
    vector<vector<pair<int, int>>> adj(n);
    for(auto& edge: edges) 
        adj[edge[0]].push_back({edge[1],edge[2]});

    // Step2: Do topo sort
    stack<int> s;
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++) {
        if(!vis[i])
            topoDFS(i, adj, s, vis);
    }

    // Step3: Take one node out of the stack and update the distance array
    vector<int> dis(n, INT_MAX);
    dis[0] = 0; //Set the src dist to 0
    while(!s.empty()) {
        int top = s.top();
        if(dis[top] != INT_MAX) { //Src se phle ki node INT_MAX hogi aur agr vo phle aa rhi h topo sort me mtlb ab unpr pauchna impossible h so inko ignore krdo aur jo INT_MAX nhi h unko process kro
            for(auto& nei: adj[top]) {
                dis[nei.first] = min(dis[nei.first], dis[top] + nei.second);
            }
        }
        s.pop();
    }
    //Before returning ques says " if it is impossible to reach any vertex, then assign -1 as distance."
    // so all our INT_MAX will be -1 that's it
    replace(dis.begin(), dis.end(), INT_MAX, -1);
    return dis;
}