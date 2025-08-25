#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Valid only in Directed Graphs

//Questions can ask 2 things.
// 1. How many SCC (Strognly connected components) are there. 
// 2. Print the SCCs

//! https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution {
  public:
    void topoDFS(int node, stack<int> &s, vector<bool> &vis, vector<vector<int>> &adj) {
        vis[node] = true;
        
        for(auto& nei: adj[node]) {
            if(!vis[nei]){
                topoDFS(nei, s, vis, adj);
            }
        }
        s.push(node);
    }
    
    void DFS(int node, vector<bool> &vis, vector<vector<int>> &adj) {
        vis[node] = true;
        
        for(auto& nei: adj[node]) {
            if(!vis[nei]){
                DFS(nei, vis, adj);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        //Step1: Doing topo sort
        stack<int> s;
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i])
                topoDFS(i, s, vis, adj);
        }
        
        //step2: Reverse the link in graph
        vector<vector<int>> adjRev(n);
        for(int i = 0; i < n; i++) {
            for(auto &it: adj[i]) {
                adjRev[it].push_back(i);
            }
        }
        
        //step3: Do DFS on stack and count SCCs
        int count = 0;
        fill(vis.begin(), vis.end(), false);
        while(!s.empty()) {
            int top = s.top();
            if(!vis[top]) {
                DFS(top, vis, adjRev);
                count++;
            }
            s.pop();
        }
        return count;
    }
};

//TC: O(3 * V+E), SC = O(2V) for vis and stack and adjRev O(V+E) so in total O(V+E)