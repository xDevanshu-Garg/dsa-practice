#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

// ****************************************SIMPLE SOLUTION*******************************
class Solution {
  public:
    set<string> solve(int i, int j, string &s1, string &s2, vector<vector<set<string>>> & dp) {
        //Base Case
        if(i < 0 || j < 0) return {""};
        
        if(dp[i][j].size() != 0) return dp[i][j];
        set<string> result;
        
        //match
        if (s1[i] == s2[j]) {
            auto prev = solve(i - 1, j - 1, s1, s2, dp);
            for (auto &str : prev) {
                result.insert(str + s1[i]);
            }
        }
        //no match
        else {
            auto left = solve(i - 1, j, s1, s2, dp);
            auto right = solve(i, j - 1, s1, s2, dp);

            int len1 = left.begin()->length();
            int len2 = right.begin()->length();

            if (len1 > len2) result = left;
            else if (len2 > len1) result = right;
            else {
                result.insert(left.begin(), left.end());
                result.insert(right.begin(), right.end());
            }
        }
        return dp[i][j] = result;
    }
    
    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        
        vector<vector<set<string>>> dp(n, vector<set<string>>(m));
        
        auto res = solve(s1.size() - 1, s2.size() - 1, s1, s2, dp);
        return vector<string>(res.begin(), res.end());
    }
};


// *********************************STRIVERS APPROACH****************************
//This doesn't handle multiple equal lengths LCS because in loops we can't try all possible combinations let's say we encounter 2 length strings 2 times then we can't go in both directions in loop then those 2 strings can be splitted into 2 more strings then 2 more so it's impossible for loops. That's why above soln is best.
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
    
    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        //n-1, m-1 will have the maximum ans
        int i = n-1, j = m-1;
        string ans = "";
        while(i >= 0 && j >= 0) {
            if(s1[i] == s2[j]) {
                ans = s1[i] + ans;
                i--, j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }
        }
        vector<string> res;
        res.push_back(ans);
        return res;
    }
};

