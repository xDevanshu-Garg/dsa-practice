#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//******************************Memoization*******************************
class Solution {
  public:
    
    int solve(int index, int k, vector<int>& dp, vector<int>& height) {
        //Base Case
        if(index == 0) return 0;

        if(dp[index] != -1) return dp[index];
        int minStep = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(index-j >= 0) {
                int jumpEnergy = solve(index-j, k, dp, height) + abs(height[index] - height[index-j]);
                minStep = min(minStep, jumpEnergy);
            }
        }
        return dp[index] = minStep;
    }

    int minCost(int k, vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(n-1, k, dp, height);
    }
}; //TC is O(n * k) SC is O(2n)

//***************************Tabulation*********************************
class Solution {
  public:

    int minCost(int k, vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int i = 1; i < n; i++) {
            int minStep = INT_MAX;

            for(int j = 1; j <= k; j++) {
                if(i-j >= 0) {
                    int jumpEnergy = dp[i-j] + abs(height[i] - height[i-j]);
                    minStep = min(minStep, jumpEnergy);
                }
            }
            dp[i] = minStep;
        }

        return dp[n-1];
    }
};