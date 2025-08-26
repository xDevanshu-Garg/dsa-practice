#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void makeSet(vector<int> &parent, vector<int> &rank) {
        int n = parent.size();
        for (int i = 0; i < n; i++) {
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
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
        if (rank[u] < rank[v])
            parent[u] = v;
        
        else if (rank[u] > rank[v])
            parent[v] = u;

        else {
            parent[v] = u;
            rank[u]++;
        }
    } 

public:
//********************Main Fn*************************
//What we did is let's say we have 4 rows and 3 cols so we're making nodes 0 1 2 3 for rows and 4 5 6 for cols 

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        //We don't know how many rows and cols are there so we'll traverse our grid to find max row and col
        int maxRow = 0, maxCol = 0;
        for(auto& it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        int m = maxRow + maxCol + 2; //max row and col are 0 bases that's why we added +2
        vector<int> parent(m);
        vector<int> rank(m);

        makeSet(parent, rank);

        for(auto& it: stones) {
            // Find parent of nodes
            int u = findParent(parent, it[0]);
            int v = findParent(parent, it[1] + maxRow + 1); // Adjusted

            if (u != v) {
                unionSet(u, v, parent, rank);
            }
        }

        //Now check how many components are there
        int count = 0;
        for(auto& it: stones) {
            int u = findParent(parent, it[0]);
            int v = findParent(parent, it[1] + maxRow + 1);

            if(u != v) count++;
        }

        return n - count;
    }
};
