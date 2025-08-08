//! https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, unordered_map<int, bool>& visited, vector<int> &ans) {
        
        ans.push_back(node);
        visited[node] = true;
        
        for(auto i: adj[node]) {
            if(!visited[i])
                DFS(i, adj, visited, ans);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        unordered_map<int, bool> visited;
        vector<int> ans;
        // for(int i = 0; i < adj.size(); i++) {
        //     if(!visited[i])
                DFS(0, adj, visited, ans); 
        // }
        return ans;
    }
};

//Commented out part is if we have disconnected graph! (also pass i instead of 0)