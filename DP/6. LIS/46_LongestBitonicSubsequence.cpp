#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // Intuition it's like this ^ shape, so we can find out LIS from front and end.
        // dp1[i] = LIS till index i (including i iteslf)
        // dp2[i] = LIS from back till index i (also i included)
        // So i is common in both so if we add dp1[i] + dp2[i] we'll get / this ans \ andbut we'll have i element two time s so we'll subtract i one time
        
        // Calc from front
        vector<int>dp1(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp1[i] = max(dp1[i], 1 + dp1[j]);
                }
            }
        }
        
        // Calc from Back
        vector<int>dp2(n, 1);
        for(int i = n-2; i >= 0; i--) {
            for(int j = n-1; j > i; j--) {
                if(nums[i] > nums[j]) {
                    dp2[i] = max(dp2[i], 1 + dp2[j]);
                }
            }
        }
        
        // Calc Longest Bitonic Subsequence
        int maxi = 0;
        for(int i = 1; i < n-1; i++) {
            // Must have both increasing and decreasing parts
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
        
        return maxi;
    }
};
