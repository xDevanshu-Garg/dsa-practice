#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! LINK: https://leetcode.com/problems/frog-jump
class Solution {
public:
    unordered_map<int, int> mp;
    vector<vector<int>> dp;
    // Because the possibility of reaching the end doesn’t just depend on which stone you’re on (i), but also on what your last jump was.
// Example: being on stone 10 with a last jump of 1 is totally different from being on stone 10 with a last jump of 5 (your future reachable stones differ).

    bool solve(int i, int k, vector<int>& stones) {
        int n = stones.size();
        if(n-1 == i) return true;

        if(dp[i][k] != -1) return dp[i][k];

        bool k0 = false, kp = false, k1 = false;

        if(k-1 > 0 && mp.find(stones[i] + k-1) != mp.end()) {
            k0 = solve(mp[stones[i] + k-1], k-1, stones);
        }
        if(mp.find(stones[i] + k) != mp.end()) {
            kp = solve(mp[stones[i] + k], k, stones);
        }
        if(mp.find(stones[i] + k+1) != mp.end()) {
            k1 = solve(mp[stones[i] + k+1], k+1, stones);
        }

        return dp[i][k] = k0 || kp || k1;
    }

    bool canCross(vector<int>& stones) {
        // Base Case
        if(stones[1] - stones[0] != 1) return false;

        int n = stones.size();
        //We'll create a map to store stones indexes.
        //Why need of indexes? Because to search next stones we need to traverse entire stones vector causing O(n^3) time
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        dp.assign(n, vector<int>(n + 1, -1));
        return solve(1, 1, stones); //Starts at index 1 with jump 1 cuz ques demanded
    }
};