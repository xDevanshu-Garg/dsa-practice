#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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
        return parent[node] = findParent(parent, parent[node]);
    }


    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
        // u = findParent(parent, u);
        // v = findParent(parent, v);

        if (rank[u] < rank[v])
            parent[u] = v;

        else if (rank[u] > rank[v])
            parent[v] = u;

        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    // **************Main fn*****************
    //Logic: count no. of disconnected components and spare edges then ans will be spareEdges >= components-1 

    //TC = O(N+E∗4Alpha)
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        vector<int> rank(n);
        int spareEdges = 0;

        // Step1: initialise make set
        makeSet(parent, rank);

        //Step2: not needed no weights so no sorting 

        // Step3: Loop over connections
        for (auto &it : connections) {
            // Find parent of nodes
            int u = findParent(parent, it[0]);
            int v = findParent(parent, it[1]);

            // if parents are not same then they're diff components
            if (u != v) {
                unionSet(u, v, parent, rank);
            }
            else spareEdges++;
        }

        int components = 0;
        for(int i = 0; i < n; i++) {
            if (parent[i] == i) components++;
        }

        if(spareEdges >= components-1) return components-1;
        return -1;
    }
};