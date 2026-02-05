#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        // Base Case
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for(int k = i; k <= j; k++) {
            int cost = nums[i-1] * nums[k] * nums[j+1]
                        + solve(i, k-1, nums, dp)
                        + solve(k+1, j, nums, dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(1, n-2, nums, dp);
    }
};

// Brute force recursion: first we have n choices then for all n choices we have n-1 choices so n * (n-1) * (n-2) ... so TC: O(n!), it will break even for n = 3, i.e. 1.3 TRILLION


//********************************************TABULATION*********************************************

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-2; i >= 1; i--) {
            for(int j = i; j <= n-2; j++) {
                int maxi = INT_MIN;
                for(int k = i; k <= j; k++) {
                    int cost = nums[i-1] * nums[k] * nums[j+1]
                                + dp[i][k-1]
                                + dp[k+1][j];
                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
};