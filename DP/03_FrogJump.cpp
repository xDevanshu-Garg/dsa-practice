#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//!https://www.geeksforgeeks.org/problems/geek-jump/1

//Base Case: if there are 0 stairs means we are at top. So minimum steps to reach at top when stairs are 0 is 0.

//*******************************MEMOIZATION****************************
class Solution {
  public:
    int solve(int n, vector<int>& height, vector<int> &dp) {
        //BC
        if(n == 0) return 0; 
        
        if(dp[n] != -1) return dp[n];

        int first = solve(n - 1, height, dp) + abs(height[n] - height[n-1]);
        int second = INT_MAX; 
        if(n > 1)
            second = solve(n - 2, height, dp) + abs(height[n] - height[n-2]);
        
        return dp[n] = min(first, second);
    }
    
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1, -1);
        return solve(n-1, height, dp);
        //whatever thing is chaning up there we make dp array out of it, In our case it's indexes
    }
};


//********************************TABULATION********************************
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        
        for(int i = 2; i < n; i++) {
            int first = dp[i-1] + abs(height[i] - height[i-1]);
            int second = INT_MAX;
            if(i > 1) second = dp[i-2] + abs(height[i] - height[i-2]);
            dp[i] = min(first, second);
        }
        
        return dp[n-1];
    }
};


//************************** SPACE OPTIMIZED *************************
//Space Optimized (Remember Base Case will increase cuz we're returning prev)
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        //Base Case
        if(n == 1) return 0;
        
        int prev2 = 0, prev = abs(height[0] - height[1]);
        
        for(int i = 2; i < n; i++) {
            int first = prev + abs(height[i] - height[i-1]);
            int second = prev2 + abs(height[i] - height[i-2]);
            int curr = min(first, second);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};