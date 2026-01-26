#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/longest-increasing-subsequence/

// Greedy fails because it will try to pick local bigger elements like 2 and then 5, but it can't think of fututre profits, so dp is used.
// We can't start at end so we'll start from 0th index, f(i,prevIndex) at index i with prevIndex max LIS
// Also shift index for dp array, because dp[...][-1] is not possible

// ***************************************MEMOIZATION************************************************

class Solution {
public: 
    vector<vector<int>> dp;

    int solve(int i, int prevIndex, vector<int>& nums) {
        // Base Case
        if(i == nums.size()) return 0;
        
        if(dp[i][prevIndex+1] != -1) return dp[i][prevIndex+1];

        // Option 1: skip current element
        int notPick = solve(i+1, prevIndex, nums);

        // Option 2: pick current element (if valid)
        int pick = 0;
        if(prevIndex == -1 || nums[prevIndex] < nums[i]) 
            pick = 1 + solve(i+1, i, nums);

        return dp[i][prevIndex+1] = max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n+1, -1));
        return solve(0, -1, nums);
    }
};


// ***************************************TABULATION************************************************

// Here because of index shifting soln is khatarnak.
// Second loop is <= i only, because prevIndex can't be more than i, but due to index shifting it's <= to i

// Base Case implicit
// dp[i][prevIndex] = LIS from 0 to i, if previously we had taken prevIndex.
// IMPORTANT: i is 0 based, while prevIndex is 1 based, because 0th index represent that you're the first one there is nothing prev.
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--) {
            for(int prevIndex = 0; prevIndex <= i; prevIndex++) {
                int notPick = dp[i+1][prevIndex];

                int pick = 0;
                if(prevIndex == 0 || nums[prevIndex-1] < nums[i]) 
                    pick = 1 + dp[i+1][i+1]; 

                dp[i][prevIndex] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }
};


// ***************************************SPACE OPTIMIZED*********************************************



// ***************************************SPACE OPTIMIZED 1 array*******************************************
