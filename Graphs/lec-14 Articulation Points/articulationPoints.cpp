#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/articulation-point2616/1

// Only diff from bridges in graph is that here we check that node must have parent and there is >= instead of >. At last when we come out of for loop we know excatly how many childs a node has so if it has no parent and it's childs are greater than 1 then it's an articulation point too cuz if we remove this node then it's children will became disconnected.
void DFS(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, 
         vector<bool> &vis, vector<bool> &isAP, vector<vector<int>> &adj) {
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int children = 0;

    for(auto& nei: adj[node]) {
        if(nei == parent) continue;

        if(!vis[nei]) {
            children++;
            DFS(nei, node, timer, disc, low, vis, isAP, adj);

            low[node] = min(low[node], low[nei]);

            // Not root and AP condition
            if(parent != -1 && low[nei] >= disc[node])
                isAP[node] = true;
        }
        else {
            low[node] = min(low[node], disc[nei]);  // use disc[nei], not low[nei]
        }
    }

    // Root AP condition
    if(parent == -1 && children > 1)
        isAP[node] = true;
}

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);        
            adj[edge[1]].push_back(edge[0]);
        }

        int timer = 0;
        vector<bool> vis(V, false);
        vector<int> low(V, -1), disc(V, -1);
        vector<bool> isAP(V, false); //to track ap and to insure dups are not inserted and also to print them in sorted order by simply traversing the vector
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]){
                DFS(i, -1, timer, disc, low, vis, isAP, adj);
            }
        }

        vector<int> ap;
        for(int i = 0; i < V; i++) {
            if(isAP[i]) ap.push_back(i);
        }

        if(ap.empty()) return {-1}; // optional: depends on the problem's specification
        return ap;
    }
};