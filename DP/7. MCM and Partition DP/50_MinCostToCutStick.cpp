#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k <= j; k++) {
            int cost = (cuts[j + 1] - cuts[i - 1])
                     + solve(i, k - 1, cuts, dp)
                     + solve(k + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(1, m - 2, cuts, dp);
    }
};


// dp[i][j] = minimum cost to cut between cuts[i-1] and cuts[j+1]
// We're inserting 0, n in cuts so that we can calculate length of stick easily. 
// Sort it because let's say arr = [2, 1, 3, 4] then if we apply MCP then our first can be at 2 or 1 or 3 or 4, so let's say we cut at 1 then the remaing stick is like 0...1 | 1...n now, for second cut we can't cut 0...1 with 2 even though in arr we are left with [2] and [3, 4]
// i > j is base case because when we cut a stick we're calling for i to k-1, so if we have i = 2, j = 5, k = 2, then new call for left is f(2, 1) so we hit base case, or if k = 5, we'll call f(6,5) for right side again base case.
// cost is calc as costs[j+1] - costs[i-1] + left + right
                                                                                                