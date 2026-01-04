#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//Subsequence: A sub string with same order of elements that may or may not be contiguious. 
//"abc": "" "a" "b" "c" "ab" "bc" "ac" "abc (2^n)

//Recursion 
// TC: O(2^n)
// SC: O(n)
//********************************************MEMOIZATION******************************************
class Solution {
  public:
    bool solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        
        if(target == 0) return true;
        if(i == 0) return target == arr[0];
        
        if (dp[i][target] != -1) return dp[i][target];

        bool include = false, exclude = false;
        if (arr[i] <= target) {
            include = solve(i - 1, target - arr[i], arr, dp);  // Include the current element
        }
        exclude = solve(i - 1, target, arr, dp);  // Exclude the current element
    
        
        return dp[i][target] = include || exclude;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n-1, sum, arr, dp);
        // f(i, sum) represents, is there a sum exist from ith index to 0 index
    }
};

// TC: O(n*target)
// SC: O(n*target * n)


//********************************************TABULATION******************************************

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        
        // BC1 at every i if target is 0 that dp state is true
        for(int i = 0; i < n; i++) dp[i][0] = true;
        //or dp[0][0] = 1, because at every i(except i=0), t=0 is calculated so whole loop is unnecessary
        
        //BC2 if i is 0 only target == arr[0] is possible
        if(arr[0] <= target) dp[0][arr[0]] = true;
        
        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= target; t++) {
                bool include = false, exclude = false;
                if (arr[i] <= t)
                    include = dp[i - 1][t - arr[i]];
                
                exclude = dp[i - 1][t];  
                
                dp[i][t] = include || exclude;
            }
        }
        
        return dp[n-1][target];
    }
};

// ***************************************SPACE OPTIMIZED****************************************

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<bool> prev(target+1, false), curr(target+1, false);
        
        prev[0] = true;
        
        prev[arr[0]] = true;
        
        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= target; t++) {
                bool include = false, exclude = false;
                if (arr[i] <= t)
                    include = prev[t - arr[i]];
                
                exclude = prev[t];  
                
                curr[t] = include || exclude;
            }
            prev = curr;
        }
        
        return prev[target];
    }
};