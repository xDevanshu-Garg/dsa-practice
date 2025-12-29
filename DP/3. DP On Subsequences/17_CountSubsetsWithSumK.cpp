#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

//******************************************MEMOIZED***************************************

class Solution {
  public:
    int solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if(i == 0) {
            if(target == 0 && arr[0] == 0) return 2;
            else if(target == 0 || target == arr[0]) return 1;
            else return 0;
        }
        
        if (dp[i][target] != -1) return dp[i][target];
        
        //Pick
        int include = 0, exclude = 0;
        if(arr[i] <= target) {
            include = solve(i-1, target - arr[i], arr, dp);
        } 
        //Not pick
        exclude = solve(i-1, target, arr, dp);
        
        return dp[i][target] = include + exclude;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int count = 0;
        return solve(n-1, target, arr, dp);
    }
};

// base case is different because array can have 0s as elements, try these two test cases
// 1. if(target == 0 && arr[0] == 0) return 2; It means [0], tar = 0, so ans is 2 i.e. [0] and [] 
// [1,0,0,3], tar = 3, [0,1,3], tar = 3
//2. As we can see in 2nd test case why didn't we return 1 when we have 3 at index 2 and keep going till index 0, because [0,3] is also a valid subset, so all the termination will happen at i = 0, otherwise we'll miss 0s ahead, maybe target become 0 at i = 5 but there are 0s at 2 and 3 index, so we can only return at i = 0, and due to pick, not pick we'll get all the subset of different kinds of 0s, like in example 1, [3], [0,3] [0,3] [0,0,3] see all 4, and these 4 will get returned at i = 0 so 4 times 1 is 4.


//*****************************************TABULAITON******************************************
//Base Cases

// for(int i = 0; i < n; i++) dp[i][0] = 1;
// if(arr[0] <= target) dp[0][arr[0]] = 1;
// if(arr[0] == 0) dp[0][0] = 2;
        
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        dp[0][0] = arr[0] == 0 ? 2 : 1; //It means at index 0 if first ele of array is 0, then ans is always 2 otherwise ans is 1, also target should be 0 too, so we wrote dp[0][0] at index 0 if tar is 0 then do the following stuff
        if(arr[0] <= target && arr[0] != 0) dp[0][arr[0]] = 1;
        
        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= target; t++) {
                //Pick
                int include = 0, exclude = 0;
                if(arr[i] <= t) {
                    include = dp[i-1][t - arr[i]];
                } 
                //Not pick
                exclude = dp[i-1][t];
                
                dp[i][t] = include + exclude;
            }
        }
        return dp[n-1][target];
    }
};

// Time: O(n × target)
// Space: O(n × target)

//*******************************************SPACE OPTIMIZED*****************************

// Time: O(n × target)
// Space: O(target)

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        
        prev[0] = arr[0] == 0 ? 2 : 1;
        if(arr[0] <= target && arr[0] != 0) prev[arr[0]] = 1; // we have already computed the value of arr[0] so we don't want to overwrite it.
        
        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= target; t++) {
                //Pick
                int include = 0, exclude = 0;
                if(arr[i] <= t) {
                    include = prev[t - arr[i]];
                } 
                //Not pick
                exclude = prev[t];
                
                curr[t] = include + exclude;
            }
            prev = curr;
        }
        return prev[target];
    }
};