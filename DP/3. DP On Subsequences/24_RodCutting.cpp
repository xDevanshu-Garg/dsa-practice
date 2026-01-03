#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/rod-cutting0840/1

// ************************************************MEMOIZATION**************************************************

//Intuition: Greedy won't work here, so we've to try all possible combinations, so we think and find out the length is like target for 3 len we can achieve it by [3], [2,1], [1,1,1], then we thought of we can either pick i+1 or we can not pick i+1(cuz ind is 1 based)
class Solution {
  public:
    int solve(int i, int target, vector<int>& price, vector<vector<int>>& dp) {
        //Base Case
        if(target == 0) return 0;
        if(i == 0) return target * price[i];
        
        if(dp[i][target] != -1) return dp[i][target];
        
        //Pick: Stay on the same i
        int pick = 0;
        if(i+1 <= target) 
            pick = price[i] + solve(i, target - (i+1), price, dp);
        
        //notPick 
        int notPick = solve(i-1, target, price, dp);
        
        return dp[i][target] = max(pick, notPick);
    }
    
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return solve(n-1, n, price, dp);
    }
};

// ************************************************TABULATION**************************************************

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        //Base Case
        //For i = 0
        for(int target = 0; target <= n; target++) {
            dp[0][target] = target * price[0];
        }
        
        for(int i = 1; i < n; i++) {
            for(int target = 0; target <= n; target++) {
                //Pick
                int pick = 0;
                if(i+1 <= target) 
                    pick = price[i] + dp[i][target - (i+1)];
                  
                //notPick  
                int notPick = dp[i-1][target];
                
                dp[i][target] = max(pick, notPick);
            }
        }
        
        return dp[n-1][n];
    }
};


// ************************************************SPACE OPTIMIZED*************************************************
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        //Base Case
        for(int target = 0; target <= n; target++) {
            prev[target] = target * price[0];
        }
        
        for(int i = 1; i < n; i++) {
            for(int target = 0; target <= n; target++) {
                //Pick
                int pick = 0;
                if(i+1 <= target) 
                    pick = price[i] + curr[target - (i+1)];
                  
                //notPick  
                int notPick = prev[target];
                
                curr[target] = max(pick, notPick);
            }
            prev = curr;
        }
        
        return prev[n];
    }
};

// *****************************************SPACE OPTIMIZED with 1 array******************************************
//We observed and realised that in take part we're using curr array so no problem here, in notTake we're using prev array but we're using exact col(Wt) so we don't need prev at all

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, 0);
        
        //Base Case
        for(int target = 0; target <= n; target++) {
            dp[target] = target * price[0];
        }
        
        for(int i = 1; i < n; i++) {
            for(int target = 0; target <= n; target++) {
                //Pick
                int pick = 0;
                if(i+1 <= target) 
                    pick = price[i] + dp[target - (i+1)];
                  
                //notPick  
                int notPick = dp[target];
                
                dp[target] = max(pick, notPick);
            }
        }
        return dp[n];
    }
};