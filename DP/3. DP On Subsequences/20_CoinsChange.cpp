#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/coin-change/

// ***************************************MEMOIZATION*************************************
class Solution {
    public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>> &dp) {
        //Base Case
        if(amount == 0) return 0;
        if(i < 0) return 1e8;
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        //pick: take the same coin again (unbounded knapsack)
        int pick = 1e8;
        if(amount - coins[i] >= 0)
        pick = 1 + solve(i, amount - coins[i], coins, dp);
        
        // notPick: move to the previous coin
        int notPick = solve(i-1, amount, coins, dp);
        
        return dp[i][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, amount, coins, dp);
        return (ans >= 1e8) ? -1 : ans;
    }
};

// ***************************************TABULATION*************************************

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e8));

        //Base Case
        for(int x = 0; x <= amount; x++) {
            dp[0][x] = (x % coins[0] == 0) ? x/coins[0] : 1e8; 
        }

        for(int i = 1; i < n; i++) {
            for(int x = 0; x <= amount; x++) {
                int pick = 1e8;
                if(x - coins[i] >= 0)
                    pick = 1 + dp[i][x - coins[i]];

                // notPick: move to the previous coin
                int notPick = dp[i-1][x];
                
                dp[i][x] = min(pick, notPick);
            }
        }

        int ans = dp[n-1][amount];
        return (ans >= 1e8) ? -1 : ans;
    }
};

// ***************************************TABULATION*************************************
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 1e8), curr(amount+1, 1e8);

        //Base Case
        for(int x = 0; x <= amount; x++) {
            prev[x] = (x % coins[0] == 0) ? x/coins[0] : 1e8; 
        }

        for(int i = 1; i < n; i++) {
            for(int x = 0; x <= amount; x++) {
                int pick = 1e8;
                if(x - coins[i] >= 0)
                    pick = 1 + curr[x - coins[i]];

                // notPick: move to the previous coin
                int notPick = prev[x];
                
                curr[x] = min(pick, notPick);
            }
            prev = curr;
        }

        int ans = prev[amount];
        return (ans >= 1e8) ? -1 : ans;
    }
};