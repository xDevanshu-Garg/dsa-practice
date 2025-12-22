//! https://leetcode.com/problems/unique-paths-ii/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//*****************************RECURSION + MEMOIZATION***********************************
class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& grid, vector<vector<int>> &dp) {

        //Base Cases
        if(m < 0 || n < 0) return 0;
        if(grid[m][n] == 1) return dp[m][n] = 0;
        if(m == 0 && n == 0) return 1; 

        if(dp[m][n] != -1) return dp[m][n];

        return dp[m][n] = solve(m-1, n, grid, dp) + solve(m, n-1, grid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, obstacleGrid, dp); 
    }
};

// *********************************TABULATION***************************************

//Filled first row and first col manually because unlike unique path 1 we can't assume there's always exactly 1 path exists at both the corners. 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        // First column
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i-1][0];
        }

        // First row
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j-1];
        }

        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                if(obstacleGrid[row][col] == 0)
                    dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }

        return dp[m-1][n-1];
    }
};

//****************************************SPACE OPTIMIZED************************************

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<int> prev(n, 0);
        prev[0] = 1;

        //First row
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[0][j] == 0)
                prev[j] = prev[j-1];
        }

        for(int row = 1; row < m; row++) {
            vector<int> curr(n, 0);

            // First column
            if(obstacleGrid[row][0] == 0)
                curr[0] = prev[0];

            for(int col = 1; col < n; col++) {
                if(obstacleGrid[row][col] == 0)
                    curr[col] = prev[col] + curr[col-1];
            }
            prev = curr;
        }

        return prev[n-1];
    }
};