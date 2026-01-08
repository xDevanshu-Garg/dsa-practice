#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/longest-palindromic-subsequence
//A palindrome reads same forward & backward, So it must be a common subsequence of s and reverse(s)

class Solution {
public:
    
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        //Base Case
        if(i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        // Match
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
        
        // No Match
        return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    }

    int longestPalindromeSubseq(string s) {
        string s2(s.rbegin(), s.rend());
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(n-1, n-1, s, s2, dp);
    }
};


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2(s.rbegin(), s.rend());
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // Match
                if(s[i-1] == s2[j-1]) 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                // No Match
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2(s.rbegin(), s.rend());
        int n = s.length();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // Match
                if(s[i-1] == s2[j-1]) 
                    curr[j] = 1 + prev[j - 1];
                
                // No Match
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[n];
    }
};

//************************REMOVED s2 **************************************

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // Match
                if(s[i-1] == s[n-j]) 
                    curr[j] = 1 + prev[j - 1];
                
                // No Match
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[n];
    }
};