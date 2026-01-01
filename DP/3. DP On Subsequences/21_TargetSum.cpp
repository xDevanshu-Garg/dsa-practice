#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/target-sum/

class Solution {
public:

    // solve(i, target): = number of ways to form sum = target using elements from index [0 ... i]
    int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {

        
        if (i == 0) {
            if (target == 0 && nums[0] == 0) return 2;

            if (target == 0 || target == nums[0]) return 1;

            // Otherwise no way
            return 0;
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int include = 0, exclude = 0;

        // Pick nums[i] if it does not exceed target
        if (nums[i] <= target) {
            include = solve(i - 1, target - nums[i], nums, dp);
        }

        // Do not pick nums[i]
        exclude = solve(i - 1, target, nums, dp);

        // Total ways = pick + not pick
        return dp[i][target] = include + exclude;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        /*
            Original equation:
            s1 - s2 = target
            s1 + s2 = total

            Solving:
            s1 = (total + target) / 2

            So problem reduces to:
            "Count subsets with sum = (total + target)/2"
        */

        // If (total + target) is odd, s1 cannot be integer
        if ((total + target) % 2 != 0)
            return 0;

        // If target is outside achievable range
        if (abs(target) > total)
            return 0;

        int s1 = (total + target) / 2;

        // dp[i][t] = number of ways to get sum t using [0..i]
        vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));

        return solve(n - 1, s1, nums, dp);
    }
};

// Time Complexity: O(n × s1)
// Space Complexity: O(n × s1)