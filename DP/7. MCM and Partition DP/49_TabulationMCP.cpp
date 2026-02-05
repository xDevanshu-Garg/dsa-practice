#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// j will always we i+1, base case are implicit, when i == j they are already 0
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
    
        for(int i = n-1; i >= 1; i--) {
            for(int j = i+1; j < n; j++) {
                int mini = INT_MAX;
                for(int k = i; k < j; k++) {
                    int step = arr[i-1] * arr[k] * arr[j]
                                + dp[i][k] + dp[k+1][j];
                    mini = min(mini, step);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};