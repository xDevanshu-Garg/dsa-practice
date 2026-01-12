#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/edit-distance/description/

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
        else {
            // Insert, Delete, Replace
            int insertOp  = solve(i, j - 1, s1, s2, dp);
            int deleteOp  = solve(i - 1, j, s1, s2, dp);
            int replaceOp = solve(i - 1, j - 1, s1, s2, dp);
    
            return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, word1, word2, dp);
    }
};


// *************************************TABULATION***********************************

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 0; i <= n; i++) dp[i][0] = i;

        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                 // If characters match
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // Insert, Delete, Replace
                    int insertOp  = dp[i][j-1];
                    int deleteOp  = dp[i-1][j];
                    int replaceOp = dp[i-1][j-1];

                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});   
                }
            }
        }
        return dp[n][m];
    }
};


// *************************************SPACE OPTIMIZED***********************************

//@ Base Case for i when j is 0 is inside first for loop

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        // Base cases
        for(int j = 0; j <= m; j++) prev[j] = j;

        for(int i = 1; i <= n; i++) {
            curr[0] = i; //Base Case
            for (int j = 1; j <= m; j++) {
                 // If characters match
                if (word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                }
                else {
                    // Insert, Delete, Replace
                    int insertOp  = curr[j-1];
                    int deleteOp  = prev[j];
                    int replaceOp = prev[j-1];

                    curr[j] = 1 + min({insertOp, deleteOp, replaceOp});   
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};


// **********************************EVEN MORE SPACE OPTIMIZED****************************
/*
At iteration (i, j):
- dp[j] → prev[j] (value from previous row, same column)
- dp[j-1] → curr[j-1] (value from current row, left column)
- upDia → prev[j-1] (value from previous row, diagonal)

? Match Case
int curr = dp[j];   // save prev[j]
dp[j] = upDia;     // dp[i][j] = prev[i-1][j-1]
upDia = curr;      // move diagonal for next j
We before overwriting, which is crucial.

? Not match case
int insertOp  = dp[j-1]; // curr[j-1]
int deleteOp  = dp[j];   // prev[j]
int replaceOp = upDia;   // prev[j-1]

upDia = dp[j];           // save prev[j] for next column
dp[j] = 1 + min(...);
We update upDia after using it, which preserves correctness.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(m+1, 0);

        // Base case
        for(int j = 0; j <= m; j++) dp[j] = j;

        for(int i = 1; i <= n; i++) {
            int upDia = dp[0]; // Store Diagonal
            dp[0] = i; //Base Case
            for (int j = 1; j <= m; j++) {
                 // If characters match
                if (word1[i-1] == word2[j-1]) {
                    int curr = dp[j];
                    dp[j] = upDia;
                    upDia = curr;
                }
                else {
                    // Insert, Delete, Replace
                    int insertOp  = dp[j-1];
                    int deleteOp  = dp[j];
                    int replaceOp = upDia;

                    upDia = dp[j];
                    dp[j] = 1 + min({insertOp, deleteOp, replaceOp});   
                }
            }
        }
        return dp[m];
    }
};