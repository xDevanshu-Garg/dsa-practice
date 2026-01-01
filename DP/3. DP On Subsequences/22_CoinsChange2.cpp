#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/coin-change-ii/description/

//*************************************MEMOIZATION***************************************
//It is same as dp 17 except we pick same index over and over again and none of the coins are 0 s0 base case is simpler 
class Solution {
    public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        //Base Case
        if(amount == 0) return 1;
        if(i < 0) return 0;
        
        if(dp[i][amount] != -1) return dp[i][amount];
        
        int pick = 0;
        if(coins[i] <= amount)
            pick = solve(i, amount - coins[i], coins, dp);

            int notPick = solve(i-1, amount, coins, dp);

            return dp[i][amount] = pick + notPick;
        }
        
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};

//*************************************TABULATION***************************************
//Intermediatory steps were causing int overflow
// Eg: [1, 2, 3, 4, 5, 6, 7, 8, 9], amount = 1000
// At some intermediate i:  dp[i][500] = 3,000,000,000  which is > INT_MAX
// But dp[i][1000] = 1,234,567    // final answer safe
// LC only guarantees the second one fits in 32-bit.
// 500 amount can have more combinations then 1000

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount+1, 0));
        vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));

        //Base Case
        for(int x = 0; x <= amount; x++) {
            if(x % coins[0] == 0) dp[0][x] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int x = 0; x <= amount; x++) {
                int pick = 0;
                if(coins[i] <= x)
                    pick = dp[i][x - coins[i]];

                int notPick = dp[i-1][x];

                dp[i][x] = (unsigned long long)pick + notPick;
            }
        }
        return dp[n-1][amount];
    }
};

// *******************************************SPACE OPTIMIZED*********************************

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount+1, 0));
        vector<long long> prev(amount+1, 0), curr(amount+1, 0);

        //Base Case
        for(int x = 0; x <= amount; x++) {
            if(x % coins[0] == 0) prev[x] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int x = 0; x <= amount; x++) {
                int pick = 0;
                if(coins[i] <= x)
                    pick = curr[x - coins[i]];

                int notPick = prev[x];

                curr[x] = (unsigned long long)pick + notPick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};