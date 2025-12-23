#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Link: https://leetcode.com/problems/triangle/
//LC doesn't accept memoized code

// *****************************************MEMOIZATION*********************************************
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        //Base Case
        if(i == triangle.size() - 1) return triangle[i][j];

        if(dp[i][j] != -1) dp[i][j];
        
        int down = solve(i+1, j, triangle, dp);
        int downRight = solve(i+1, j+1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, downRight);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        //Filling the dp array
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i-1].push_back(-1);
            }
        }

        return solve(0, 0, triangle, dp);
    }
};

//*************************************TABULATION****************************************

//Base Case: We need to pre compute the values of n-1 row => dp[n-1][*] by this method
// for(int i = 0; i < n; i++) {
//     dp[n-1][i] = triangle[n-1][i];
// }

//But we just wrote dp = triangle so that this step is skipped, now we started from n-2 because n-1th row is already computed, also j needed to run exactly i times and i is 0 based so i+1 times or 0 to n(exactly)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

// *****************************************SPACE OPTIMIZED*********************************************
//Initialized dp array with n-1 row of triangle
//At each step of a row we observed that we don't need dp[i] value anymore because we'll not use that value again in future, so we store our current value as dp[i], before dp[i] meant value at ith place in next row, now it meant dp[i] have value of ith element in curr row. So need need of 2 vectors.  
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};