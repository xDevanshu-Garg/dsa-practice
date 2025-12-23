//! https://leetcode.com/problems/minimum-path-sum/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Normal recursive way TC would be 2^(n*m)
// *****************************************MEMOIZATION*********************************************
//TC = O(m * n)
//  SC = dp[m][n] → O(m * n), Depth → (m-1) + (n-1) total O(m*n)
class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // Base case
        if (m == 0 && n == 0)
            return grid[0][0];

        if (m < 0 || n < 0)
            return 1e9;  // large value to avoid invalid paths

        if (dp[m][n] != -1)
            return dp[m][n];

        int up = solve(m - 1, n, grid, dp);
        int left = solve(m, n - 1, grid, dp);

        return dp[m][n] = grid[m][n] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};

// **************************************Tabulation*********************************************

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //Base Case
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(i == 0 && j == 0) continue;
                int up = 0, left = 0;

                if(i-1 < 0) up = 1e9; 
                else up = dp[i-1][j];

                if(j-1 < 0) left = 1e9;
                else left = dp[i][j-1];

                dp[i][j] = grid[i][j] + min(up, left);
            }
        }

        return dp[m-1][n-1];
    }
};

//Alternative way of writing if else 
//else if(i == 0) dp[i][j] = grid[i][j] + dp[i][j-1];
// else if(j == 0) dp[i][j] = grid[i][j] + dp[i-1][j];
// else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);

// *************************************SPACE OPTIMIZED********************************************
//Observation: We don't need two arrays because
// At column j:
// dp[j] still stores prev[j] (up)
// dp[j-1] already became curr[j-1] (left) see after remaining rows loop dp[0] += grid[i][0]
// So one array plays both roles.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);

        // Base case
        dp[0] = grid[0][0];

        // First row (can only come from left)
        for (int j = 1; j < n; j++) {
            dp[j] = grid[0][j] + dp[j - 1];
        }

        //Remaning rows
        for(int i = 1; i < m; i++) {
            // First col (can only come from up)
            dp[0] = dp[0] + grid[i][0];

            for(int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
            }
        }
        
        return dp[n-1];
    }
};