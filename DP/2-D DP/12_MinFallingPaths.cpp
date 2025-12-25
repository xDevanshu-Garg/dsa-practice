//! Link: https://leetcode.com/problems/minimum-falling-path-sum/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;    

//This ques has variable starting point as well as ending point, so start whereever you want but keep in mind if you have n variable points then recrusion will start from n points.

//****************************************MEMOIZATION**********************************
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        //Base Case
        if(j < 0 || j > matrix.size() - 1) return 1e9;
        if(i == 0) return matrix[0][j];

        if(dp[i][j] != -1) return dp[i][j];

        //up
        int up = solve(i-1, j, matrix, dp);
        //left
        int upLeft = solve(i-1, j-1, matrix, dp);
        //right
        int upRight = solve(i-1, j+1, matrix, dp);


        return dp[i][j] = matrix[i][j] + min(up, min(upLeft, upRight));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, solve(n-1, j, matrix, dp));
        }
        return ans;
    }
};

//****************************************TABULATION**********************************

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //Base Case
        dp[0] = matrix[0];

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == 0)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                else if(j == n-1)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                else 
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
            }
        }

        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
        //or
        // return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

//or
        // int up = dp[i-1][j];
        // int upLeft = (j > 0) ? dp[i-1][j - 1] : 1e9;
        // int upRight = (j < n - 1) ? dp[i-1][j + 1] : 1e9;

        // dp[i][j] = matrix[i][j] + min({up, upLeft, upRight});

//****************************************SPACE OPTIMIZED**********************************

//Played smart and used only 1 array by observing and seeing that only because of 1 block we're needing a second array so we made a variable for that guy
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];

        for(int i = 1; i < n; i++) {
            int prevLeft = 1e9;

            for(int j = 0; j < n; j++) {
                int prevUp = dp[j]; // storing prev up because dp[j] will store curr ans

                int up = prevUp;
                int upLeft = prevLeft;
                int upRight = (j < n-1) ? dp[j+1] : 1e9;
                
                dp[j] = matrix[i][j] + min({up, upLeft, upRight});
                prevLeft = prevUp; // store for next column
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};