#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// ******************************************GREEDY-1*********************************
// Buy only at increasing slope, and sell 
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mini = INT_MAX, profit = 0;

        for(auto price : prices) {
            mini = min(mini, price);
            //If price increases then sell the stock for profit and reset mini
            if(price - mini > 0) {
                profit += price - mini;
                mini = price;
            }
        }
        return profit;
    }
};

// Pure greedy: If the stock price of tomorrow is greater than today, buy it today and sell it tomorrow(or directly count profit)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;

        for(int i = 0; i < prices.size() - 1; i++) {
            if(prices[i] < prices[i+1]) 
                total += prices[i+1] - prices[i];
        }
        return total;
    }
};


// ***************************************MEMOIZATION************************************************
// Base Case: At last, if you canBuy now, don't buy because duniya khtm h, aur bech sakte ho aur abhi tk becha nhi h to kya kr rhe ho becho!

class Solution {
    public:
    int solve(int i, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        // Base Case
        int n = prices.size();
        if(i == n - 1) {
            if(canBuy) return 0;
            else return prices[n-1];
        } 
        // or if (i == n || j == 4) return 0; (but upper onces helped us to write tabulation)
        
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        
        // Buy 
        if(canBuy) {
            // Buy: canBuy changes
            int c1 = -prices[i] + solve(i+1, 0, prices, dp);

            // Not Buy: canBuy doesn't change
            int c2 = 0 + solve(i+1, 1, prices, dp);
            
            return dp[i][canBuy] = max(c1, c2);
        }
        // Sell
        else {
            // Sell
            int c1 = +prices[i] + solve(i+1, 1, prices, dp);
            
            // Not Sell
            int c2 = 0 + solve(i+1, 0, prices, dp);
            
            return dp[i][canBuy] = max(c1, c2);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        // 1: Can buy, 2: Can sell
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};

// ***************************************TABULATION************************************************

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        //Base Case
        dp[n-1][1] = 0;
        dp[n-1][0] = prices[n-1];
        
        for(int i = n-2; i >= 0; i--) {
            for(int canBuy = 1; canBuy >= 0; canBuy--) {
                // Buy 
                if(canBuy)
                    dp[i][canBuy] = max(dp[i+1][0] - prices[i], dp[i+1][1]);
                    // Sell
                else
                dp[i][canBuy] = max(dp[i+1][1] + prices[i], dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};

// ***************************************SPACE OPTIMIZED*********************************************

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2, 0), curr(2, 0);

        //Base Case
        next[1] = 0;
        next[0] = prices[n-1];

        for(int i = n-2; i >= 0; i--) {
            for(int canBuy = 1; canBuy >= 0; canBuy--) {
                // Buy 
                if(canBuy)
                    curr[canBuy] = max(next[0] - prices[i], next[1]);
                // Sell
                else
                    curr[canBuy] = max(next[1] + prices[i], next[0]);
            }
            next = curr;
        }
        return next[1];
    }
};