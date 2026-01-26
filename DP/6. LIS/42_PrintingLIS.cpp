#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

//****************************************NON INTUITIVE CODE***************************************

// See this video if you wanna know how this works.
//! https://www.youtube.com/watch?v=IFfYfonAFGc

// Basically it computes best LIS including that index, and leverage that in order to find out best LIS 
// Start i from 1 (0th i is 1 already), j < i, because prevIndex can't be greater than or equal to i
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for(int i = 1; i < n; i++) {
            for(int prevIndex = 0; prevIndex < i; prevIndex++) {
                if(nums[prevIndex] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prevIndex]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// ***********************************************PRINTING******************************************

class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();

        // dp[i] = To store LIS till that index
        vector<int> dp(n, 1);

        // hash[i] = To locate prev index like LL
        vector<int> hash(n);

        // Initialize hash so that each element points to itself
        for (int i = 0; i < n; i++) {
            hash[i] = i;
        }

        int maxi = 1;       // Length of longest LIS
        int lastIndex = 0;  // Index where LIS ends

        // Build dp and hash arrays
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct LIS using hash array
        vector<int> ans;
        ans.push_back(arr[lastIndex]);

        while (lastIndex != hash[lastIndex]) {
            lastIndex = hash[lastIndex];
            ans.push_back(arr[lastIndex]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// nums = [10 20 3 40]
// hash = [0  0  2 1]
// lastIndex = 3, maxi = 3