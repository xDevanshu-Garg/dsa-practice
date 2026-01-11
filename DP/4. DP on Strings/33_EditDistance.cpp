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
// if char match no operations needed to perform, else check all 3 condns, if we insert only j moves, if we del only i moves and in rep operation both moves. (also add 1 cuz 1 operation is done)
//Base Case: if i is empty then we need to insert j+1 chars, if j is empty then delete i+1 chars

class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>> &dp) {
        //Base Case
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if (dp[i][j] != -1) return dp[i][j];

        // Match
        if(s1[i] == s2[j]) 
            return dp[i][j] = 0 + solve(i-1, j-1, s1, s2, dp);

        // Not Match
        else {
            int ins = 1 + solve(i, j-1, s1, s2, dp);
            int del = 1 + solve(i-1, j, s1, s2, dp);
            int rep = 1 + solve(i-1, j-1, s1, s2, dp);

            return dp[i][j] = min({ins, del, rep});
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};

// ****************************************MEMOIZATION-2***********************************
// If we call with (n,m) then some things change, base case is for i,j == 0, we return i and j because they are not indices anymore they are length now, match condn is for i-1, j-1
class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // Base cases
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        // If characters match
        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
        }

        // Insert, Delete, Replace
        int insertOp  = solve(i, j - 1, s1, s2, dp);
        int deleteOp  = solve(i - 1, j, s1, s2, dp);
        int replaceOp = solve(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, word1, word2, dp);
    }
};


// *************************************TABULATION***********************************



// *************************************SPACE OPTIMIZED***********************************


// **********************************EVEN MORE SPACE OPTIMIZED****************************
