#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/unique-paths/

// f(i, j) = number of ways to reach cell (i, j) from (0, 0)
//If I found out the ans coming from up and left side then I can add them and I'll have the ans for that state(i,j) i.e. f(i,j) = f(up) + f(left)

// ******************************Recursion + Memoization********************************
class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp) {

        //Base Cases
        if(m == 0 && n == 0) return 1; 
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        //Up
        int up = solve(m-1, n, dp);
        
        //left
        int left = solve(m, n-1, dp);

        return dp[m][n] = up + left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, dp); 
    }
};

//****************************************Tabulation*************************************
//I initialized the grid with 1 because first row and column always have one path, so base cases are implicitly handled then in both for loops we started with value 1, so both left and upper corners are not overridden.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[m-1][n-1];
    }
};

//*********************************Space Optimized*****************************************
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1); //for upper row
        vector<int> curr(n, 1); //for curr row

        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                curr[col] = prev[col] + curr[col-1];
            }
            prev = curr;
        }
        return curr[n-1];
    }
};