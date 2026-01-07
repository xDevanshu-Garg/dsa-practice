#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Problem types on DP on Strings: Comparisions, replaces/edits

//Subsequence: A string with same order of elements that may or may not be contiguious. 
//"abc": "" "a" "b" "c" "ab" "bc" "ac" "abc (2^n)

//! https://leetcode.com/problems/longest-common-subsequence/

// LCS cannot be solved greedily because sometimes you must skip a matching character to allow a longer match later.
// s1 = "abcxyz", s2 = "gbxyzc"
// Output: "bxyz"
// But greedy will give output bc or c or xyz yz z so max is xyz of 3 length not bxyz of len 4, why? because sometimes you must skip a matching character to allow a longer match in future and future can only be seen by DP.

//TC of Brute force: O(2^n * 2^m)

//*****************************************MEMOIZATION************************************

class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        // Base Case
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        // Match
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
        }
        // No match
        return dp[i][j] = max(solve(i-1, j, s1, s2, dp),solve(i, j-1, s1, s2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, text1, text2, dp);
    }
};

//*****************************************TABULATION************************************

//See in memo base case was when i or j is -ve to be precise only -1, so we can't represent -1 in array so we shifted the index, old -> -1, 0 ... n-1, now -> 0, 1 ... n and same for m too.
//dp array size is n+1 * m+1
//Base Case is dp[i][0] = 0 and dp[0][j] = 0 where i is 0 to n and j is 0 to m, but we don't need to write it because we're initializing dp array with 0, so it's implicitly 0.
//Loops: Base Case for i = 0 and j = 0 is already computed so loop with  i = 1 to <= n, and j = 1 to <= m
//Match condition is diff because we shifted the index, 0 .. n-1 to 1 to n, so if we're writing n then we want to access n-1, if we're writing 4 we want to access 3 so we need to i-1.
// [. . . . .] -> [. . . . .]
// -1 0 1 2 3  ->  0 1 2 3 4

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
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

        return dp[n][m];
    }
};


//*****************************************SPACE OPTIMIZATION************************************

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Match
                if (s1[i-1] == s2[j-1])
                    curr[j] = 1 + prev[j-1];
                // No match
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[m];
    }
};