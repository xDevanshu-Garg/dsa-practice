#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Link: https://leetcode.com/problems/house-robber/
/*
//*****************************Memoization**********************************
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int> &dp) {
        if(i == 0) return nums[i];
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];
        //Pick
        int pick = nums[i] + solve(i-2, nums, dp);
        //Not-Pick
        int nPick = solve(i-1, nums, dp);

        return dp[i] = max(pick, nPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return solve(n-1, nums, dp);
    }
};
*/

/*
//**************************************TABULATION**************************
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; //Necesarry Base Case otherwise dp[1] will cause index out of bounds error.

        vector<int>dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            //Pick
            int pick = nums[i] + dp[i-2];
            //Not-Pick
            int nPick = dp[i-1];

            dp[i] = max(pick, nPick);
        }
        return dp[n-1];
    }
};
*/

//************************SPACE OPTIMIZED************************
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            //Pick
            int pick = nums[i] + prev2;
            //Not-Pick
            int nPick = prev;

            int curr = max(pick, nPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};