#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, int parent, vector<vector<int>> &adj, unordered_map<int, bool> &visited) {
    visited[node] = true;
    for(auto neighbour: adj[node]) {
        if(visited[neighbour] && neighbour != parent) return true;
        if(!visited[neighbour]) {
            bool cycleDetected = isCyclicDFS(neighbour, node, adj, visited);
            if(cycleDetected) return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //Creating adj list
    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    
    for(int start = 1; start <= n; start++) {
        
        if(!visited[start]){
    
            bool ans = isCyclicDFS(start, -1, adj, visited);
            if(ans) return "Yes";
        }
    }
    return "No";
}