#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

// ***************************************MEMOIZATION************************************************

class Solution {
public:
    int solve(int i, int j, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        // Base Case
        int n = prices.size();
        if(i == n) 
            return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // Buy
        if(j == 0) {
            return dp[i][j] = max(-prices[i] + solve(i+1, j+1, prices, fee, dp), 
                        solve(i+1, j, prices, fee, dp));
        }
        // Sell
        else {
            return dp[i][j] = max(prices[i] - fee + solve(i+1, 0, prices, fee, dp), 
                        solve(i+1, j, prices, fee, dp));
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 0, prices, fee, dp);
    }
};

// ***************************************TABULATION************************************************




// ***************************************SPACE OPTIMIZED*********************************************



// ***************************************SPACE OPTIMIZED 1 array*********************************************
