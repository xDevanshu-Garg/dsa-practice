#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/minimum-removals-to-balance-array/

// Problem: Find the largest subarray in the sorted array such that max <= min * k

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int maxLen = 0;
        
        for (int j = 0; j < n; j++) {
            // Build step: expand window by moving j
            // Nothing to do

            // If invalid, undo from left
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++; // Shrink window
            }
            
            // Valid window
            maxLen = max(maxLen, j - i + 1);
        }
        
        return n - maxLen;
    }
};