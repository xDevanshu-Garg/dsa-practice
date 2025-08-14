#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void makeSet(vector<int> &parent, vector<int> &rank) {
    int n = parent.size();
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// find the parent's root and update parent[node] directly (path compression)
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

int DSU(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank);
}