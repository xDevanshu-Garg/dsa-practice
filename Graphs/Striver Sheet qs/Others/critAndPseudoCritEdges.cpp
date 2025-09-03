#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree

class DSU {
public:
    vector<int> parent, rank; 

    DSU(int n) { //constructor
        parent.resize(n + 1);
        rank.resize(n + 1, 0);  // Initially, each set has rank 0
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    // Custom comparator to sort edges by weight
    bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    }

    // Kruskal's Algorithm to find MST weight
    int minimumSpanningTree(vector<vector<int>> &edges, int n, vector<int> &skip) {
        int totalWt = 0;
        DSU dsu(n);

        // Step 1: Sort all edges by weight
        sort(edges.begin(), edges.end(), cmp);

        // Step 2: Loop through edges
        for (auto &edge : edges) {
            if(edge == skip) continue;
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // If u and v belong to different sets means they're diff components, include the edge
            if (dsu.findParent(u) != dsu.findParent(v)) {
                totalWt += wt;
                dsu.unionByRank(u, v);
            }
        }
        return totalWt;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        //First Kruskal to find min weight
        vector<int> skip = {0, 0, 0};
        int minWeight = minimumSpanningTree(edges, n, skip);

        //Now finding critical and Pseudo-Critical Edges
        //Critical: If removing edge increases weight of MST
        //Pseudo-Critical: If removing edge weight remains same

        vector<vector<int>> ans(2);
        unordered_set<int> crit, pseudoCrit;
        for(auto& edge: edges) {
            int wt = minimumSpanningTree(edges, n, edge);
            
            if(wt == minWeight) {
                pseudoCrit.insert(edge[0]);
                pseudoCrit.insert(edge[1]);
            }
            else if(wt > minWeight) {
                crit.insert(edge[0]);
                crit.insert(edge[1]);
            }
        }

        //Push critical elements into ans[0]
        for(auto &it: crit) {
            ans[0].push_back(it);
        }
        //push pseudo-critical ele into ans[1]
        for(auto &it: pseudoCrit) {
            ans[1].push_back(it);
        }
        return ans;
    }
};