#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/description/

class Solution
{
    int n, LOG;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    const int MOD = 1e9 + 7;

public:
    void dfs(int node, int parent)
    {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++)
        {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (auto child : adj[node])
        {
            if (child == parent)
                continue;

            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }

    int lca(int u, int v)
    {
        if (depth[u] > depth[v])
            swap(u, v);

        int diff = depth[v] - depth[u];

        for (int j = LOG - 1; j >= 0; j--)
        {
            if (diff & (1 << j))
                v = up[v][j];
        }

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--)
        {
            if (up[u][j] != up[v][j])
            {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    // long long modPow(long long base, long long exp) {
    //     long long ans = 1;

    //     while(exp) {
    //         if(exp & 1) ans = (ans * base) % MOD;
    //         exp >>= 1;
    //         base = (base * base) % MOD;
    //     }

    //     return ans;
    // }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges,
                                  vector<vector<int>> &queries)
    {
        n = edges.size() + 1;

        LOG = 0;
        while ((1 << LOG) <= n)
            LOG++;
        adj.resize(n + 1);
        up.assign(n + 1, vector<int>(LOG, 0));
        depth.assign(n + 1, 0);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);

        vector<int> ans;
        vector<long long> pow(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            pow[i] = (2LL * pow[i - 1]) % MOD;
        }

        for (auto &query : queries)
        {
            int u = query[0];
            int v = query[1];

            int p = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[p];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back((int)pow[dist - 1]);
        }

        return ans;
    }
};