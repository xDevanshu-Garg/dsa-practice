#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
//If we know the longest palindromic sub-sequence is x and the length of the string is n then, what is the answer to this problem? It is n - x as we need n - x insertions to make the remaining characters also palindrome.

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

        return n - prev[n];
    }
};