#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path) {
        vis[node] = path[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei] && dfs(nei, adj, vis, path))
                return true;
            else if (path[nei]) // visited in current path → cycle
                return true;
        }

        path[node] = 0; // backtrack
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto it: prerequisites)
            adj[it[0]].push_back(it[1]);

        vector<int> vis(n, 0), path(n, 0);

        for (int i = 0; i < n; i++)
            if (!vis[i] && dfs(i, adj, vis, path))
                return false;

        return true;
    }
};