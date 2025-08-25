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
// TC = O(V+E) why? because in DFS you only traverse a node once so total 1 node and while doing it you traverse all edges connected from that node only onces too so in total you traverse all nodes and all edges only onces so TCis sum of V and E

// suppose We have 100 houses and 200 roads we'll traverse all 100 houses only onces and 200 roads only onces in dir graph and in undir maybe twice but it doesn't matter it's still E so total O(V+E)