#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Only one thing is diff that we're using a new data strucuture called path or DfsCall which will track if this node's DFS called already happened or not.
// If a node has exhausted all it's neighbour and still there is no cycle then we backtrack dfs call of that node to be false but visited[node] is still true because we're saying that this node has been visited but there is no scope of cycle so let's remove this from DfsCall cuz DfsCall or path only contains the node that still have scope.

//Contest friendly version
// tc = O(N+E) node + edges SC = O(n)
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

bool detectCycle(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n + 1); // 1-indexed
    for (auto &e : edges)
        adj[e.first].push_back(e.second);

    vector<int> vis(n + 1, 0), path(n + 1, 0);

    for (int i = 1; i <= n; i++)
        if (!vis[i] && dfs(i, adj, vis, path))
            return true;

    return false;
}

//! https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTabValue=SUBMISSION
bool isCycleDFS(int node, vector<vector<int>> &adj, int visited[], int DfsCall[]) {
    visited[node] = true;
    DfsCall[node] = true;
    for (auto neighbour : adj[node]) {
        // Do DFS
        if (!visited[neighbour]) {
            bool cycleDetected = isCycleDFS(neighbour, adj, visited, DfsCall);
            if (cycleDetected)
                return true;
        }
        // Check if cycle is present or not
        else if (visited[neighbour] && DfsCall[neighbour])
            return true;
    }
    DfsCall[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // Let's make adj list
    vector<vector<int>> adj(n + 1);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
    }

    // Cycle detection using DFS
    int visited[n + 1] = {0};
    int DfsCall[n + 1] = {0};

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool ans = isCycleDFS(i, adj, visited, DfsCall);
            if (ans)
                return true;
        }
    }
    return false;
}

