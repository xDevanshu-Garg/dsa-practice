#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// custom comparator
bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank) {
    int n = parent.size();
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// find the parent?s root and update parent[node] directly (path compression)
// Stop when you're your own parent
int findParent(vector<int> &parent, int node) {
    if (node == parent[node])
        return node;

    // assign the new parent for node
    parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
        parent[u] = v;

    else if (rank[u] > rank[v])
        parent[v] = u;

    else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n) {
    vector<int> parent(n);
    vector<int> rank(n);
    int totalWt = 0;

    // Step1: initialise make set
    makeSet(parent, rank);

    // Step2: Sort our edges acc to weight
    sort(edges.begin(), edges.end(), cmp);

    // Step3: Loop over edges
    for (auto &it : edges) {
        // Find parent of nodes
        int u = findParent(parent, it[0]);
        int v = findParent(parent, it[1]);
        int wt = it[2];

        // if parents are not same then they're diff components
        if (u != v) {
            totalWt += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return totalWt;
}