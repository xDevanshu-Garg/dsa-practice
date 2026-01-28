#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/number-of-longest-increasing-subsequence/

/*
LeetCode 673 - Number of Longest Increasing Subsequence

Pattern:
- Classic LIS DP with an extra count tracking
- For every index, we store:
  1) Length of LIS ending at that index
  2) Number of LIS ending at that index

dp[i] = {length, count}
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        /*
        dp[i].first  -> Length of LIS ending at index i
        dp[i].second -> Number of LIS of that length ending at index i

        Initialization:
        - Every element alone forms an LIS of length 1
        - Count is also 1 initially
        */
        vector<pair<int, int>> dp(n, {1, 1});

        int maxi = 1;  // Stores length of overall LIS
        int ans = 0;   // Stores total number of LIS

        /*
        STEP 1: Compute LIS length and count for each index
        */
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                // Valid increasing condition 
                if(nums[j] < nums[i]) {

                    
                    // Case 1: If extending subsequence at j gives a longer LIS
                    if(dp[i].first < 1 + dp[j].first) {
                        dp[i].first  = 1 + dp[j].first;
                        dp[i].second = dp[j].second;
                    }

                    
                    // Case 2: If extending subsequence at j gives the SAME LIS length → increase number of ways
                    else if(dp[i].first == 1 + dp[j].first) {
                        dp[i].second += dp[j].second;
                    }
                }
            }
            // Update maximum LIS length found so far
            maxi = max(maxi, dp[i].first);
        }

        
        // STEP 2: Count total number of LIS with maximum length
        for(int i = 0; i < n; i++) {
            if(dp[i].first == maxi) {
                ans += dp[i].second;
            }
        }

        return ans;
    }
};

/*
---------------- REVISION SUMMARY ----------------
- dp[i] stores {LIS length, number of LIS}
- If a longer LIS is found → replace length & count
- If same length LIS is found → add counts
- Final answer = sum of counts where LIS length is maximum
- Time Complexity: O(n^2)
- Space Complexity: O(n)
-------------------------------------------------
*/