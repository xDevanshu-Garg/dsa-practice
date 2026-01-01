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
        
        int pick = 0; // INT_MIN so it is not considered (good practice but we don't need it as values are only positive, so notPick can minimum be 0, it would be wrong if let's say pick = 0, notPick = -10, so max will be 0, which is wrong)
        //Pick
        if(W - wt[i] >= 0)
        pick = val[i] + solve(i-1, W-wt[i], val, wt, dp);
        
        //nonPick
        int notPick = solve(i-1, W, val, wt, dp);
        
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

// *****************************************SPACE OPTIMIZED with 1 array******************************************
//We observed that both pick and notPick are dependent on prev array, and in pick case prev array col will always lies left side, so what we did is we reversed the 2nd for loop(col), now we are modifing right side values and we're always using left side values, so left side values are safe.
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<int> dp(W+1, 0);
        
        //You can start taking item 0 after weight == wt[0]
        //So fill all the cells of row 1 after the threshold value
        for(int Wt = wt[0]; Wt <= W; Wt++) {
            dp[Wt] = val[0];
        }
            
        for(int i = 1; i < n; i++) {
            for(int Wt = W; Wt >= 0; Wt--) {
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