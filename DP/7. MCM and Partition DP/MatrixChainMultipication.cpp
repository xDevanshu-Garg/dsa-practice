#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Pattern: When their and multiple ways to solve a problem and you want the best onw 
// Like (1 + 2 + 3) * (4) gives diff ans and (1 + 2) + (3 * 4) gives diff ans depending upon where you place brackets.

//! https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        // Base Case:
        if(i == j) return 0; 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i; k < j; k++) {
            int step = arr[i-1] * arr[k] * arr[j] + solve(i, k, arr, dp) + 
                        solve(k+1, j, arr, dp);
            mini = min(mini, step);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n-1, arr, dp);
    }
};