#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ! https://www.naukri.com/code360/problems/prim-s-mst_1095633

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    //Let's make an adj list
    vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing
    for (auto &edge : g) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since it's undirected
    }

    // Result MST
    vector<pair<pair<int, int>, int>> mst;

    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    //Step1: Push initial node to PQ: Start from node 1 (assumption)
    //We can take any node as starting node
    // PQ structure: {{weight, Node}, parent} (Weight is first cuz sorting will happen from weight)
    // Also we can omit parent if we don't need. But in this ques we need to return edge b/w two nodes so we'll require parent-child relation

    pq.push({{0, 1}, -1}); 
    vector<bool> vis(n+1, false);
    vis[1] = 1;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int wt = top.first.first;
        int node = top.first.second;
        int parent = top.second;

        //! Don't forget this step
        if(vis[node]) continue; //Not considered(We've already visited this node with better weight)
        vis[node] = true; // considered If not visited earlier, now It's visited and we're gonna explore it's meighbours

        //After visited we know surely that this node is included in our ans.
        mst.push_back({{parent, node}, wt});

        //Push adj nodes into pq
         for (auto &[adjNode, edgeWt] : adj[node]) {
            if(!vis[adjNode]) {
                pq.push({{edgeWt, adjNode}, node});
            }
        }
    }
    return mst;
}


//Cleaned Version
// ! https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        //adj list
        vector<vector<pair<int, int>>> adj(V); // node -> {NeiNode, weight}
        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<bool> vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        int totalWei = 0;
        
        pq.push({0, 0}); //Started from 0 {wei, node}
        
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int wei = top.first;
            int node = top.second;
            
            if(vis[node]) continue; //Skip visited nodes
            vis[node] = true;
            totalWei += wei;
            
            for(auto &it: adj[node]) {
                int edgeWei = it.second;
                int neiNode = it.first;
                
                if(!vis[neiNode]) {
                    pq.push({edgeWei, neiNode});
                }
            }
        }
        return totalWei;
    }
};