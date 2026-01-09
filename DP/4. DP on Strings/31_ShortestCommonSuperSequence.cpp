#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/shortest-common-supersequence/

//Lcs increase when char match, so when char matches that char is common in both string so include it
//if it doesn't match try both possibility, but if you're omitting a guy from s1, make sure to add it because that is not the part of LCS, so we've to include it in SCS independently, and same if we're omitting s2's char

class Solution {
public:
    string solve(int i, int j, string &s1, string &s2, vector<vector<string>> &dp) {
        // Base cases
        if (i == 0) return s2.substr(0, j);
        if (j == 0) return s1.substr(0, i);
        
        if (!dp[i][j].empty()) return dp[i][j];
        
        // If last characters match
        if (s1[i - 1] == s2[j - 1])
            dp[i][j] = solve(i-1, j-1, s1, s2, dp) + s1[i-1];
        
            // If last characters do not match
        else {
            string x = solve(i-1, j, s1, s2, dp) + s1[i-1];
            string y = solve(i, j-1, s1, s2, dp) + s2[j-1];

            dp[i][j] = (x.length() < y.length()) ? x : y;
        }
        
        return dp[i][j];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));

        return solve(n, m, str1, str2, dp);
    }
};
//Memoized solution, But it'll give MLE, because dp[i][j] stores a string so SC: o(n*m * n+m) n*m for dp size and each cell can have n+m length string, so even for n,m = 1000, SC: o(1000*1000 * 2000) = 2*10^9 = 2GB

//* Optimal soln: 
// Compute LCS length DP (integers only → O(n·m) memory)
// Reconstruct the Shortest Common Supersequence from the LCS table

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        //Calculating dp array
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Match
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                // No match
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        //Now we have our dp array, same as memo, if match then push that guy into ans and move dia up, if doesn't match compare up vs left whichever is bigger go there but before going, if we're going up then we'll not be able to have that s1[i-1] element ever again so push it, if we're going left then we'll not have s2[j-1] element ever again so push it first then go in that direction.
        
        //At last if any string remains push it. 
        //Reverse the ans.

        int i = n, j = m;
        string ans = "";

        while(i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                ans.push_back(s1[i-1]);
                i--, j--;
            }
            else if (dp[i-1][j] > dp[i][j-1] ) { // Up
                ans.push_back(s1[i-1]);
                i--;
            }
            else { // Left
                ans.push_back(s2[j-1]);
                j--;
            }
        }

        //Some char remains so push them all
        while(i > 0) ans.push_back(s1[--i]);
        while(j > 0) ans.push_back(s2[--j]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};