#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// ***************************************MEMOIZATION************************************************

class Solution {
public:
    int solve(int i, int j, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        // Base Case: No days left → no profit
        if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // Buy
        if(j == 0) {
            // Buy on that day or skip
            return dp[i][j] = max(-prices[i] + solve(i+1, j+1, prices, dp), 
                                    solve(i+1, j, prices, dp));
        }
        else if(j == 1) {
            // Sell or skip
            return dp[i][j] = max(prices[i] + solve(i+1, j+1, prices, dp), 
                                    solve(i+1, j, prices, dp));
        }
        return dp[i][j] = solve(i+1, 0, prices, dp);
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(3, -1));
        return solve(0, 0, prices, dp);
    }
};

// j = 0 → can BUY
// j = 1 → can SELL
// j = 2 → cooldown (forced skip)

// ***************************************TABULATION************************************************

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));

        // Base Case
        dp[n-1][1] = prices[n-1];

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < 3; j++) {
                if(j == 0) 
                    // Buy on that day or skip
                    dp[i][j] = max(-prices[i] +  dp[i+1][j+1], dp[i+1][j]);
                
                else if(j == 1) 
                    // Sell or skip
                    dp[i][j] = max(prices[i] + dp[i+1][j+1], dp[i+1][j]);
                
                else 
                    dp[i][j] = dp[i+1][0];
            }
        }
        return dp[0][0];
    }
};


// ***************************************SPACE OPTIMIZED*********************************************



// ***************************************SPACE OPTIMIZED 1 array*********************************************
