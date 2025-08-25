#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Used to find if 2 nodes are in same component or not in O(1) because while making graph we keep track of it's parent so if a new edge or node joins the graph we don't need to DFS/BFS entire graph again.
//Used in Dynamic Graphs (Graphs that's keep chaning it's configurations as seen above)

//TC is O(4α) which is as good as constant

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
    u = findParent(parent, u);
    v = findParent(parent, v);
    //if rank of node is greator make it parent so we can find parent in lesser time
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


//Union by size is same as union by rank. 
// Initialize a size vector with size 1 (cuz every node have atleast 1 node in starting i.e. itself) size counts how many nodes are there in tree like structure.
// if size of both u and v are same make anyone parent let's say parent[v] = u then increse size of u by size[u] = size[u] + size[v] and then if size[u] < size[v] so again parent[u] = v and size[v] += size[u] simple as hell 