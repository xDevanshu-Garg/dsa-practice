#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/max-dot-product-of-two-subsequences/

class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        //Base Case
        if(i < 0 || j < 0) return -1e8;
        if(dp[i][j] != -1e8) return dp[i][j];
        //Pick
        int pick = nums1[i] * nums2[j] + max(0, solve(i-1, j-1, nums1, nums2, dp));
        
        //Not pick
        int skip1 = solve(i - 1, j, nums1, nums2, dp);
        int skip2 = solve(i, j - 1, nums1, nums2, dp);

        return dp[i][j] = max({pick, skip1, skip2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1e8));
        return solve(n-1, m-1, nums1, nums2, dp);
    }
};

// nums1 = [-1, 5]
// nums2 = [ 2, 3]
// Best answer = 5 * 3 = 15

// Without max(0, ...):
// pick(1,1) = 5*3 + (-2) = 13 ❌

// With max(0, ...):
// pick(1,1) = 5*3 + 0 = 15 ✅