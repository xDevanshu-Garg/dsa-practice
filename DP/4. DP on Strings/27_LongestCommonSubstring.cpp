#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Substring: A string from oringal strings that follows relative order and is contiguous. Total: n *(n+1)/2

//! https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
//! https://leetcode.com/problems/maximum-length-of-repeated-subarray/

//DP state must contain exactly the information needed to make the next decision without ambiguity.

//dp[i][j] = length of longest common substring ENDING EXACTLY at i and j
//answer = max over all solve(i, j)

// ***********************************TABULATION************************
class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int ans = 0;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;   // reset (continuity breaks)
                }
            }
        }
        return ans;
    }
};

// ***********************************SPACE OPTIMIZATION**********************************

class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int ans = 0;

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                } else {
                    curr[j] = 0;   // reset (continuity breaks)
                }
            }
            prev = curr;
        }
        return ans;
    }
};