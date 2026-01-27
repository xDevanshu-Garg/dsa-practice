#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    bool compareByLength(string& a, string& b) {
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        // Sort according to length: Because a word can only be formed from shorter words.
        // sort(words.begin(), words.end(), compareByLength); //or use lamba fn
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.length() < b.length(); });

        // Apply LIS logic
        int n = words.size();
        vector<int> dp(n, 1);
        unordered_map<string, int> mp;
        mp[words[0]] = dp[0];
        int maxi = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < words[i].length(); j++) {
                string word = words[i];
                word.erase(j, 1); // Erase 1 character starting from position 'j'
                if(mp.find(word) != mp.end()) {
                    dp[i] = max(dp[i], mp[word] + 1);
                }
            }
            mp[words[i]] = dp[i];
            if(dp[i] > maxi) 
                maxi = dp[i];
        }
        return maxi;
    }
};

//! Explanation code: 
// (Also here we didn't use full vector because we don't need it)
/*
LeetCode 1048 - Longest String Chain
Pattern: LIS on Strings (DP + Hashing)


Core Idea:
- Treat this problem as LIS, but on strings instead of numbers
- A word can be chained only from a word of length (len - 1)
- Instead of inserting a character, delete one character to find predecessor
*/


class Solution {
public:
    int longestStrChain(vector<string>& words) {
    /*
    STEP 1: Sort words by increasing length
    Reason:
    - A word can only be formed from a strictly shorter word
    - After sorting, all valid predecessors appear before the current word
    */
        sort(words.begin(), words.end(),
            [](string& a, string& b) { return a.length() < b.length(); });

        // dp[word] = length of the longest string chain ending at 'word'
        // Using unordered_map for O(1) predecessor lookup
        
        unordered_map<string, int> dp;

        // Stores the maximum chain length found so far
        int ans = 1;


        
        // STEP 2: Process each word in increasing length order
        for (string& w : words) {
            // Base Case: Every word itself forms a chain of length 1
            dp[w] = 1;


            /*
            STEP 3: Generate all possible predecessors
            - Remove one character at every index
            - This simulates the reverse of adding one character
            */
            for (int i = 0; i < w.size(); i++) {
                string prev = w;
                prev.erase(i, 1);

                /*
                If predecessor exists, extend its chain
                dp[w] = max(dp[w], dp[prev] + 1)
                */
                if (dp.count(prev)) {
                    dp[w] = max(dp[w], dp[prev] + 1);
                }
            }
            ans = max(ans, dp[w]);
        }
        return ans;
    }
};