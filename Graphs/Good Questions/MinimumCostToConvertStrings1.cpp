#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/minimum-cost-to-convert-string-i

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source == target) return 0;

        // Precomputing shortest distance between original to changed array
        int n = original.size();
        vector<vector<pair<int, int>>> adj(26);
        for(int i = 0; i < n; i++) {
            int u = original[i] - 'a', v = changed[i] - 'a', c = cost[i];
            adj[u].push_back({v, c});
        }

        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        for(int i = 0; i < 26; i++) {
            dist[i][i] = 0;
            // pair<int, int> -> {dist, node}
            priority_queue<pair<long long, int>,
                vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

            pq.push({0,i});
            
            while(!pq.empty()) {
                auto[nodeDist, node] = pq.top(); pq.pop();

                if(nodeDist > dist[i][node]) continue;

                for(auto[neiNode, neiWeight]: adj[node]) {
                    if(nodeDist + neiWeight < dist[i][neiNode]) {
                        dist[i][neiNode] = nodeDist + neiWeight;
                        pq.push({dist[i][neiNode], neiNode});
                    }
                }
            }
        }

        // Now that we have dist calculated, we can now calculate min cost to src to target
        long long total = 0;
        for(int i = 0; i < source.size(); i++) {
            int src = source[i] - 'a', tar = target[i] - 'a';
            if(dist[src][tar] == INT_MAX) return -1;
            else if(src != tar) total += dist[src][tar];
        }
        return total;
    }
};