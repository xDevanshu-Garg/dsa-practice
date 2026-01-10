#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//There are two types of dp on strings problem when there are two strings
//One is LCS second is counting, lcs is used when we want max, min

//! https://leetcode.com/problems/distinct-subsequences/

// ****************************************MEMOIZATION***********************************
class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        //Base Case
        if(j < 0) return 1; //If j has exhausted means we've a ans
        if(i < 0) return 0; //When j is not empty but i is means we can't find a subsequence in s now.

        if (dp[i][j] != -1) return dp[i][j];

        // Match
        if(s[i] == t[j]) {
            int c1 = solve(i-1, j-1, s, t, dp);
            int c2 = solve(i-1, j, s, t, dp);
            return dp[i][j] = c1 + c2;
        }

        // Not Match
        else
            return dp[i][j] = solve(i-1, j, s, t, dp);

    }

    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};

// *************************************TABULATION***********************************

//Use unsigned long long other wise - overflow
//Why? Because tabulation counts all cells it doesn't prune

class Solution {
    public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
        
        // Base case: empty t
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
            
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[n][m];
    }
};

// *************************************SPACE OPTIMIZED***********************************
//if we observe, we'll see that we're using upper diagnoal, and upper row only so we can definitely space optimize
//IMPORTANT: We've to remove for loop for base case, so we observed and saw prev row is fully 0 except prev[0] = 1, and we don't care about curr row it can all be 1 because it'll be recomputed except curr[0], which is expicitly 1.

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<unsigned long long> prev(m+1, 0), curr(m+1, 1);
        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return prev[m];
    }
};

// **********************************EVEN MORE SPACE OPTIMIZED****************************
//As i said we only need up and upper dia, so we moved j loop in reverse
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<unsigned long long> dp(m+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i-1] == t[j-1])
                    dp[j] = dp[j-1] + dp[j];
                else
                    dp[j] = dp[j];
            }
        }

        return dp[m];
    }
};