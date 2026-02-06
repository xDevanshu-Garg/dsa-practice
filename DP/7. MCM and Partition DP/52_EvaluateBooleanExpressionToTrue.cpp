#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

// TC: O(n * n * 2) * n, SC: O(n^2) + Aux

// int mod
class Solution {
  public:
    int solve(int i, int j, int isTrue, string& s, vector<vector<vector<int>>>& dp) {
       // Base Case
       if(i > j) return 0;
       if(i == j) {
           if(isTrue) return s[i] == 'T';
           else return s[i] == 'F';
       }
       if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ways = 0;
        for(int k = i+1; k <= j-1; k+=2) {
            // lT = leftTrue
            int lT = solve(i, k-1, 1, s, dp);
            int lF = solve(i, k-1, 0, s, dp);
            int rT = solve(k+1, j, 1, s, dp);
            int rF = solve(k+1, j, 0, s, dp);
            
            if(s[k] == '&') {
                if(isTrue) ways += lT * rT;
                else ways += lF * rF + lT * rF + lF * rT;
            }
            else if(s[k] == '|') {
                if(isTrue) ways += lT * rT + lT * rF + lF * rT;
                else ways += lF * rF;
            }
            else {
                if(isTrue) ways += lT * rF + lF * rT;
                else ways += lT * rT + lF * rF;
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    
    int countWays(string &s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n-1, 1, s, dp);
    }
};

// Tabulate this too.
// I guess you'll need long long too