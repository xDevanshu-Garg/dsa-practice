#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.naukri.com/code360/problems/minimum-spanning-tree_631769

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

// Custom comparator to sort edges by weight
bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

// Kruskal's Algorithm to find MST weight
int minimumSpanningTree(vector<vector<int>> &edges, int n) {
    int totalWt = 0;
    DSU dsu(n);

    // Step 1: Sort all edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Step 2: Loop through edges
    for (auto &edge : edges) {
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