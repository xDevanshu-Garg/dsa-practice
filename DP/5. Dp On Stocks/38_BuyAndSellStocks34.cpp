#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// ***************************************MEMOIZATION************************************************

// Same as sticks 3, just make dp of size k*2
class Solution {
public:
    int solve(int i, int j, int k, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        // Base Case
        if(i == n || j == k*2) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // Buy
        if(j % 2 == 0) {
            // Buy on that day or skip
            return dp[i][j] = max(-prices[i] + solve(i+1, j+1, k, prices, dp), 
                                    solve(i+1, j, k, prices, dp));
        }
        else {
            // Sell or skip
            return dp[i][j] = max(prices[i] + solve(i+1, j+1, k, prices, dp), 
                                    solve(i+1, j, k, prices, dp));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(k*2, -1));
        return solve(0, 0, k, prices, dp);
    }
};

// ***************************************TABULATION************************************************

// Make an empty state "done"(see in dp initialization), it's purpose is to just serve as empty state and prevent overflow.
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(k*2+1, 0));

        // Base Case
        for(int j = 0; j < k*2; j++) {
            if(j % 2 == 1) dp[n-1][j] = prices[n-1];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < k*2; j++) {
                if(j % 2 == 0) {
                    // Buy on that day or skip
                    dp[i][j] = max(-prices[i] + dp[i+1][j+1], dp[i+1][j]);
                }
                else {
                    // Sell or skip
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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> next(k*2+1, 0), curr(k*2+1, 0);

        // Base Case
        for(int j = 0; j < k*2; j++) {
            if(j % 2 == 1) next[j] = prices[n-1];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < k*2; j++) {
                if(j % 2 == 0) {
                    // Buy on that day or skip
                    curr[j] = max(-prices[i] + next[j+1], next[j]);
                }
                else {
                    // Sell or skip
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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(k*2+1, 0);

        // Base Case
        for(int j = 0; j < k*2; j++) {
            if(j % 2 == 1) dp[j] = prices[n-1];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j < k*2; j++) {
                if(j % 2 == 0) {
                    // Buy on that day or skip
                    dp[j] = max(-prices[i] + dp[j+1], dp[j]);
                }
                else {
                    // Sell or skip
                    dp[j] = max(prices[i] + dp[j+1], dp[j]);
                }
            }
        }
        return dp[0];
    }
};