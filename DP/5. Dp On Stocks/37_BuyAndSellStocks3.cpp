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

// Same just inside loop is not equals to j, because j == 4 is always 0
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, 0));

        // Base Case
        for(int j = 0; j < 4; j++) {
            if(j == 0 || j == 2) dp[n-1][j] = 0;
            else dp[n-1][j] = prices[n-1];
        }
        dp[n-1][4] = 0;

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < 4; j++) {
                // Buy
                if(j == 0 || j == 2) {
                    dp[i][j] = max(-prices[i] + dp[i+1][j+1], dp[i+1][j]);
                }
                // Sell
                else {
                    dp[i][j] = max(prices[i] + dp[i+1][j+1], dp[i+1][j]);
                }
            }
        }
        
        return dp[0][0];
    }
};


// ***************************************SPACE OPTIMIZED*********************************************

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(5, 0), curr(5, 0);
        
        // Base Case
        for(int j = 0; j < 4; j++) {
            if(j == 0 || j == 2) next[j] = 0;
            else next[j] = prices[n-1];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < 4; j++) {
                // Buy
                if(j == 0 || j == 2) {
                    curr[j] = max(-prices[i] + next[j+1], next[j]);
                }
                // Sell
                else {
                    curr[j] = max(prices[i] + next[j+1], next[j]);
                }
            }
            next = curr;
        }
        
        return next[0];
    }
};

// ***************************************SPACE OPTIMIZED 1 array*********************************************

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(5, 0);

        // Base Case
        for(int j = 0; j < 4; j++) {
            if(j == 0 || j == 2) dp[j] = 0;
            else dp[j] = prices[n-1];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < 4; j++) {
                // Buy
                if(j == 0 || j == 2) {
                    dp[j] = max(-prices[i] + dp[j+1], dp[j]);
                }
                // Sell
                else {
                    dp[j] = max(prices[i] + dp[j+1], dp[j]);
                }
            }
        }
        
        return dp[0];
    }
};