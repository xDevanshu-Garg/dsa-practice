#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Binary Lifting Cheatsheet

up[node][j]
= 2^j-th ancestor of node

Recurrence:
up[node][j] = up[ up[node][j-1] ][j-1]

LCA Steps:

1. Equalize depths.
2. If same node => LCA found.
3. Lift both from large jumps to small jumps.
4. Return parent.

Distance Formula:

dist(u,v)
= depth[u] + depth[v] - 2*depth[lca(u,v)]

Useful For:

✓ LCA
✓ Distance Queries
✓ K-th Ancestor
✓ Tree Path Problems
✓ Competitive Programming
*/

/*
========================================
BINARY LIFTING + LCA TEMPLATE
========================================

What it does:
- Finds Lowest Common Ancestor (LCA) of two nodes.
- Finds distance between two nodes.
- Lifts a node k levels up in O(log N).

When to use:
- Tree queries.
- Distance between nodes.
- K-th ancestor queries.
- Path related problems.

Complexities:
Preprocessing: O(N log N)
LCA Query:     O(log N)
Distance:      O(log N)
Space:         O(N log N)
*/

class BinaryLifting
{
private:
    int n;
    int LOG;

    vector<vector<int>> adj;
    vector<vector<int>> up; // up[node][j] = 2^j-th ancestor
    vector<int> depth;

public:
    BinaryLifting(int nodes, vector<vector<int>> &edges, int root = 1)
    {

        n = nodes;

        LOG = 0;
        while ((1 << LOG) <= n)
            LOG++;

        adj.resize(n + 1);
        up.assign(n + 1, vector<int>(LOG, 0));
        depth.assign(n + 1, 0);

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(root, 0);
    }

    void dfs(int node, int parent)
    {

        up[node][0] = parent;

        // Build Binary Lifting Table
        for (int j = 1; j < LOG; j++)
        {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int child : adj[node])
        {

            if (child == parent)
                continue;

            depth[child] = depth[node] + 1;

            dfs(child, node);
        }
    }

    /*
    Lift node upward by k levels.

    Example:
    kthAncestor(13, 5)
    => move node 13 up by 5 edges
    */
    int kthAncestor(int node, int k)
    {

        for (int j = LOG - 1; j >= 0; j--)
        {

            if (k & (1 << j))
                node = up[node][j];
        }

        return node;
    }

    /*
    Lowest Common Ancestor

    Example:
    lca(8, 11)
    */
    int lca(int u, int v) {

        if (depth[u] > depth[v])
            swap(u, v);

        // Bring v to same depth as u
        int diff = depth[v] - depth[u];

        for (int j = LOG - 1; j >= 0; j--) {

            if (diff & (1 << j))
                v = up[v][j];
        }

        if (u == v)
            return u;

        // Lift both until just below LCA
        for (int j = LOG - 1; j >= 0; j--) {

            if (up[u][j] != up[v][j]) {

                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    /*
    Distance between two nodes.

    Formula:
    depth[u] + depth[v] - 2 * depth[LCA]
    */
    int distance(int u, int v) {

        int p = lca(u, v);

        return depth[u] + depth[v] - 2 * depth[p];
    }

    /*
    Get depth of a node from root.
    */
    int getDepth(int node) {
        return depth[node];
    }
};

/*
    ! Example Usage
        int n = edges.size() + 1;

        BinaryLifting tree(n, edges);

        int p = tree.lca(7, 10);

        int dist = tree.distance(7, 10);

        int ancestor = tree.kthAncestor(10, 3);
*/