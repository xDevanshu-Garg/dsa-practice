#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

// ***************************************MEMOIZATION************************************************

// Here Greedy fails: 1 2 3 200 4 200
// We can make 3d dp for i,canBuy,transaction, or we can shrink last 2 params in 1
// 0- nothing happened (We can buy)
// 1- we have bought now we can sell
// 2- we have sold 1st time now we can buy 2nd time
// 3- we have bought 2nd time now we can sell
// 4- We have sold it, nothing to do now(done)

class Solution {
public:
    int solve(int i, int j, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();

        // Base Case
        if(j == 4) return 0;
        if(i == n-1) {
            if(j == 0 || j == 2) return 0;
            else return prices[n-1];
        }
        // or if (i == n || j == 4) return 0; (but upper onces helped us to write tabulation)

        if(dp[i][j] != -1) return dp[i][j];

        // Buy
        if(j == 0 || j == 2) {
            return dp[i][j] = max(-prices[i] + solve(i+1, j+1, prices, dp), 
                        solve(i+1, j, prices, dp));
        }
        // Sell
        else {
            return dp[i][j] = max(prices[i] + solve(i+1, j+1, prices, dp), 
                        solve(i+1, j, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5, -1));

        return solve(0, 0, prices, dp);
    }
};

// ***************************************TABULATION************************************************




// ***************************************SPACE OPTIMIZED*********************************************
