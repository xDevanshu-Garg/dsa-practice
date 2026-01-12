#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/edit-distance/description/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//There are two types of dp on strings problem when there are two strings
//One is LCS second is counting, lcs is used when we want max, min

//! https://leetcode.com/problems/distinct-subsequences/

// ****************************************MEMOIZATION***********************************
// if match or we have '?' then move both pointers, else check if we have '*' or not, if not directly return false, if yes then we've 2 conditions, but I thought 3 (it'll work with 3 also but 1st case is redundant)
// 3 cases: Make a char using * and consume *, make a char using star but don't cosume * (keep for future use) and Last don't match a char using * (empty case) 
// But actually '*' means: matches empty and matches one or more characters, so 1st condition automatically fulfilled by combination of both, how? take a char(i-1) but don't move j, then match empty(i stays same j = j-1)

/*
bool c1 = solve(i-1, j-1, s, p, dp); //Not needed
bool c2 = solve(i-1, j, s, p, dp);
bool c3 = solve(i, j-1, s, p, dp);
*/
class Solution {
public:
    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // Base Case 
        if(i == 0) {
            if(j == 0) 
                return true;
            else 
                for(int x = 0; x < j; x++) {
                    if(p[x] != '*') return false;
                }
                return true;
        }
        if(j == 0) return false;

        if (dp[i][j] != -1) return dp[i][j];

        // Match
        if(s[i-1] == p[j-1] || p[j-1] == '?') 
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        // Not Match
        else {
            // '*'
            if(p[j-1] == '*') {
                bool c1 = solve(i-1, j, s, p, dp);
                bool c2 = solve(i, j-1, s, p, dp);
                return dp[i][j] = c1 | c2;
            }
        }
        //if chars don't match and we don't have * and ?
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, s, p, dp);
    }
};

// *************************************TABULATION***********************************
// Dp array change to bool instead of int.
// Base Case if len og both string is 0 then true, now if i = 0 so check how many j's are * if 2 * then 2 true, after that all false, 3rd base case is handled by default, when j = 0 (means no one to match) and i is something other than 0 we want false.
// last dp[i][j] = false, because we don't have any return now, so it will override our ans, so write it in else case
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // Base case: empty string & empty pattern
        dp[0][0] = true;
        for(int j = 1; j <= m; j++) {
            if(p[j-1] == '*')
                dp[0][j] = true;
            else break;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // Match
                if(s[i-1] == p[j-1] || p[j-1] == '?') 
                    dp[i][j] = dp[i-1][j-1];
                // Not Match
                // '*'
                else if(p[j-1] == '*') {
                    bool c1 = dp[i-1][j]; 
                    bool c2 = dp[i][j-1];
                    dp[i][j] = c1 | c2;
                }
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};


// *************************************SPACE OPTIMIZED***********************************

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<bool> prev(m+1, false), curr(m+1, false);

        // Base Case
        prev[0] = true;
        // Pattern like "***" can match empty string
        for(int j = 1; j <= m; j++) {
            if(p[j-1] == '*')
                prev[j] = true;
            else break;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // Match
                if(s[i-1] == p[j-1] || p[j-1] == '?') 
                    curr[j] = prev[j-1];
                // Not Match
                // '*'
                else if(p[j-1] == '*') {
                    bool c1 = prev[j]; 
                    bool c2 = curr[j-1];
                    curr[j] = c1 | c2;
                }
                else curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};
