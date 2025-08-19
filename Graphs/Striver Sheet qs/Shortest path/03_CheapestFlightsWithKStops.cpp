#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1740837642/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Making adj list
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        // q = {step, {dist, node}}
        q.push({0, {0, src}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()) {
            auto front = q.front(); q.pop();
            int stops = front.first;
            int cost = front.second.first;
            int node = front.second.second;

            if(stops > k) continue;

            for(auto nei: adj[node]) {
                int neiNode = nei.first;
                int neiWei = nei.second;

                if(cost + neiWei < dist[neiNode] && stops <= k) {
                    dist[neiNode] = cost + neiWei;
                    q.push({stops+1, {cost + neiWei, neiNode}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};