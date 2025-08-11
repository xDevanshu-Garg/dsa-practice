//! https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
//We'll be using minHeap
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        //First make adj list
        vector<vector<pair<int, int> >> adj(V);
        for(auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        //Make a dist vector
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        //Need a minHeap to store {dist, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // 0 dist of 0 node
        
        while(!pq.empty()) {
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (nodeDist > dist[node]) continue; // skip outdated
            
            for(auto& nei: adj[node]) {
                int neiNode = nei.first;
                int neiWeight = nei.second;
                
                if(nodeDist + neiWeight < dist[neiNode]) {
                    dist[neiNode] = nodeDist + neiWeight;
                    pq.push({dist[neiNode], neiNode});
                }
            }
        }
        return dist;
    }
};

//! Why no erase() in priority_queue?
// A priority_queue in C++ is just a wrapper over a binary heap stored in a vector —
// removing an arbitrary element would require searching for it in O(n) time, so they don’t implement it.

// If you don’t need erase(), use priority_queue — it’s lighter and usually faster in practice.

// If you really want to remove specific entries (e.g., to control memory usage), use set.