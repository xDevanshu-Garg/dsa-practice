#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// ************************************************MEMOIZATION**************************************************

class Solution {
  public:
    int solve(int i, int W, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp) {
        //Base Case
        if(W == 0) return 0;
        if(i < 0) return 0;
        
        if(dp[i][W] != -1) return dp[i][W];
        //pick
        int pick = 0;
        if(wt[i] <= W)
            pick = val[i] + solve(i, W-wt[i], val, wt, dp);
        //notPick
        int notPick = solve(i-1, W, val, wt, dp);
        
        return dp[i][W] = max(pick, notPick);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};

// ************************************************TABULATION**************************************************

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        //You can start taking item 0 after weight == wt[0]
        //So fill all the cells of row 1 after the threshold value
        //But now we can pick multiple val[0] so pick as many as possible by Wt/wt[0] * val[0]
        for(int Wt = wt[0]; Wt <= W; Wt++) {
            dp[0][Wt] = (Wt / wt[0]) * val[0];
        }
            
        for(int i = 1; i < n; i++) {
            for(int Wt = 0; Wt <= W; Wt++) {
                int pick = 0, notPick = 0;
                //Pick
                if(Wt - wt[i] >= 0)
                    pick = val[i] + dp[i][Wt-wt[i]];
                    
                //nonPick
                notPick = dp[i-1][Wt];
                
                dp[i][Wt] = max(pick, notPick);
            }
        }
        return dp[n-1][W];
    }
};

// ************************************************SPACE OPTIMIZED*************************************************
//Pick value comes from curr
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        int n = val.size();
        
        vector<int> prev(W+1, 0), curr(W+1, 0);

        for(int Wt = wt[0]; Wt <= W; Wt++) {
            prev[Wt] = (Wt / wt[0]) * val[0];
        }
            
        for(int i = 1; i < n; i++) {
            for(int Wt = 0; Wt <= W; Wt++) {
                int pick = 0, notPick = 0;
                //Pick
                if(Wt - wt[i] >= 0)
                    pick = val[i] + curr[Wt-wt[i]];
                    
                //nonPick
                notPick = prev[Wt];
                
                curr[Wt] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[W];
    }
};

// *****************************************SPACE OPTIMIZED with 1 array******************************************
//We observed and realised that in take part we're using curr array so no problem here, in notTake we're using prev array but we're using exact col(Wt) so we don't need prev at all

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int W) {
        int n = val.size();
        
        vector<int> dp(W+1, 0);
    
        for(int Wt = wt[0]; Wt <= W; Wt++) {
            dp[Wt] = (Wt / wt[0]) * val[0];
        }
            
        for(int i = 1; i < n; i++) {
            for(int Wt = 0; Wt <= W; Wt++) {
                int pick = 0, notPick = 0;
                
                //Pick
                if(Wt - wt[i] >= 0)
                    pick = val[i] + dp[Wt-wt[i]];
                    
                //nonPick
                notPick = dp[Wt];
                
                dp[Wt] = max(pick, notPick);
            }
        }
        return dp[W];
    }
};