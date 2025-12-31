#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// ************************************************MEMOIZATION**************************************************

class Solution {
  public:
  
  int solve(int i, int W, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp) {
      //Base Case
        if(W == 0) return 0;
        if(i < 0) return 0; 
        
        if(dp[i][W] != -1) return dp[i][W];
        
        int pick = 0, notPick = 0;
        //Pick
        if(W - wt[i] >= 0)
        pick = val[i] + solve(i-1, W-wt[i], val, wt, dp);
        
        //nonPick
        notPick = solve(i-1, W, val, wt, dp);
        
        return dp[i][W] = max(pick, notPick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        
        return solve(n-1, W, val, wt, dp);
    }
};


// ************************************************TABULATION**************************************************

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        //You can start taking item 0 after weight == wt[0]
        //So fill all the cells of row 1 after the threshold value
        for(int Wt = wt[0]; Wt <= W; Wt++) {
            dp[0][Wt] = val[0];
        }
            
        for(int i = 1; i < n; i++) {
            for(int Wt = 0; Wt <= W; Wt++) {
                int pick = 0, notPick = 0;
                //Pick
                if(Wt - wt[i] >= 0)
                    pick = val[i] + dp[i-1][Wt-wt[i]];
                    
                //nonPick
                notPick = dp[i-1][Wt];
                
                dp[i][Wt] = max(pick, notPick);
            }
        }
        return dp[n-1][W];
    }
};

// ************************************************SPACE OPTIMIZED*************************************************

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        //You can start taking item 0 after weight == wt[0]
        //So fill all the cells of row 1 after the threshold value
        for(int Wt = wt[0]; Wt <= W; Wt++) {
            prev[Wt] = val[0];
        }
            
        for(int i = 1; i < n; i++) {
            for(int Wt = 0; Wt <= W; Wt++) {
                int pick = 0, notPick = 0;
                //Pick
                if(Wt - wt[i] >= 0)
                    pick = val[i] + prev[Wt-wt[i]];
                    
                //nonPick
                notPick = prev[Wt];
                
                curr[Wt] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[W];
    }
};