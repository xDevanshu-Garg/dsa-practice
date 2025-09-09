#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//**********************Memoizaiton*******************************
class Solution{
public:
    int fibDp(int n, vector<int> &dp) {
        //Base Case
        if(n <= 1) return n;

        if(dp[n] != -1) return dp[n];
        return dp[n] = fibDp(n-1, dp) + fibDp(n-2, dp);
    }

    int fib(int n) {
        vector<int> dp(n+1, -1); //n+1 because 0 -> n indexes
        return fibDp(n, dp);
    }
};

//****************************TABULATION*******************************
class Solution{
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1, -1);
        
        dp[0] = 0, dp[1] = 1;

        //Start the loop from 2 till n because we already know the value of 0,1
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//****************************TABULATION SPACE OPTIMIZED*******************************
class Solution{
public:
    int fib(int n) {
        if (n <= 1) return n;
        // vector<int> dp(n+1, -1); No need
        
        int prev2 = 0, prev = 1;

        //Start the loop from 2 till n because we already know the value of 0,1
        for(int i = 2; i <= n; i++) {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

//Normal recursion is O(2^n) because of overlapping subproblems
// DP is good TC is O(n) but SC is O(2n)
// Tabulation is better TC is O(n) but SC is O(n)
// Tabulation with space optimized is best TC is O(n) but SC is constant O(1)