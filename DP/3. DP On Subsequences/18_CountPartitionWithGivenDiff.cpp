#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

class Solution {
public:
    int solve(int i, int sum, int diff, int totalSum, vector<int>& arr, vector<vector<int>>& dp) {

        // Base case: all elements considered
        if (i < 0) {
            if (sum - (totalSum - sum) == diff)
                return 1;
            return 0;
        }

        if (dp[i][sum] != -1)
            return dp[i][sum];

        // Exclude current element
        int notTake = solve(i - 1, sum, diff, totalSum, arr, dp);

        // Include current element
        int take = solve(i - 1, sum + arr[i], diff, totalSum, arr, dp);

        return dp[i][sum] = take + notTake;
    }

   int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        for (int x : arr) totalSum += x;

        // dp[i][sum] → number of ways using elements [0..i] with current sum
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

        return solve(n - 1, 0, diff, totalSum, arr, dp);
    }
};

//This solution works but we are checking if we met the condition inside the base case, unlike normal dp where target is 0 then we surely knows we've the ans, in this we can't directly know the ans by looking at sum parameter like we're doing in prev quess by looking at target, so we need to make this a target problem too.

//Also it seems like there are many targets but in reality the condn sum - (totalSum - sum) == diff  or s1 - s2 == diff, will be true only once in it's lifetime, because s1 must be bigger then only we'll get possitive diff.

// eg: totalSum = 17, diff = 3, it will be true only once i.e s1 = 10, s2 = 7, like this eg there will always be 1 true condn. not even s1 = 7 and s2 = 10, this way diff is -3, so false

// ***************************************EASY WAY***********************************
/*
s1 - s2 = diff
s1 - (totalSum - s1) = diff
2*s1 - totalSum = diff
s1 = (diff + totalSum) / 2

so now we have a target which is s1, just remeber this that numerator should be even, because we're dealing with integers.

*/


// *************************************TABULATION***********************************

class Solution {
public:
    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = 0;
        for (int x : arr) totalSum += x;

        // dp[i][s] = number of ways using elements [0..i] to get sum = s
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));

        // Base case: i = 0
        // Exclude arr[0]
        dp[0][0] = 1;

        // Include arr[0]
        dp[0][arr[0]] += 1;   // handles arr[0] == 0 correctly (becomes 2)

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= totalSum; sum++) {

                // Not take
                dp[i][sum] += dp[i - 1][sum];

                // Take
                if (sum >= arr[i]) {
                    dp[i][sum] += dp[i - 1][sum - arr[i]];
                }
            }
        }

        // Apply your difference condition at the end
        int ans = 0;
        for (int sum = 0; sum <= totalSum; sum++) {
            if (sum - (totalSum - sum) == diff) {
                ans += dp[n - 1][sum];
            }
        }

        return ans;
    }
};
//What it does is it counts all the possible ways of generating the different kinds of sum, so at last row(n-1) we have all the sums, now we will find our own usefull sum at the end. 

//Or using target approach we can directly use that tabulation technique or use target to directly jump at dp[n-1][target], and this will be our ans, but this is wastage of storage and iterations as target can be much less then totalSum + 1.

// *************************************TABULATION(Good way)***********************************

class Solution {
    public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int totalSum = 0;
        for (int x : arr) totalSum += x;
        
        // If impossible
        if ((totalSum + diff) % 2 != 0) return 0;
        
        int target = (totalSum + diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // Base cases
        dp[0][0] = 1;
        if (arr[0] <= target) dp[0][arr[0]]++;

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                // Not take
                dp[i][sum] += dp[i - 1][sum];

                // Take
                if(sum >= arr[i])
                    dp[i][sum] += dp[i - 1][sum - arr[i]];
            }
        }
        
        return dp[n - 1][target];
    }
};

// *************************************SPACE OPTIMIZED***********************************