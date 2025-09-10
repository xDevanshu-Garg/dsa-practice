#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/climbing-stairs/

//BTW this is also same as fib numbers
// *****************MEMOIZATION*****************************
class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if (n < 0) return 0;
        if (n == 0) return 1;

        //step 2
        if(dp[n] != -1) return dp[n];
        //step1
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
    int climbStairs(int n) {
        // if (n < 0) return 0;
        // if (n == 0) return 1;

        // //RR
        // return climbStairs(n-1) + climbStairs(n-2);

        //step 0
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};


//************************** TABULATION *************************
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1, dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//************************** SPACE OPTIMIZED *************************

class Solution {
public:
    int climbStairs(int n) {
        
        int prev2 = 1, prev = 1;

        for(int i = 2; i <= n; i++) {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};