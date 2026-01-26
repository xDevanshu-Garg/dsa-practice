#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/largest-divisible-subset/
//! I observed that it's a LIS style dp problem, but I've to print, so I applied dp 42 logic.

/****************************************************
 * LeetCode 368 – Largest Divisible Subset
 *
 * PATTERN:
 * --------
 * LIS (Longest Increasing Subsequence) style DP
 * Condition changes from:
 *      nums[i] > nums[j]
 * to:
 *      nums[i] % nums[j] == 0
 *
 * KEY IDEA:
 * ---------
 * A subset is unordered, BUT we sort the array
 * to impose an order so DP becomes easy.
 *
 * Sorting does NOT change the validity of a subset.
 * Because a subset in non contiguious and non ordered.
 * 
 ****************************************************/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        /*************** STEP 1: SORT ****************/
        // Sorting helps us only check nums[i] % nums[j] == 0
        // for j < i (LIS-style)
        sort(nums.begin(), nums.end());

        int n = nums.size();

        /*************** STEP 2: DP ARRAY *************/
        // dp[i] = length of largest divisible subset ending at index i
        vector<int> dp(n, 1);

        /*************** STEP 3: HASH (PARENT) ********/
        // hash[i] stores the previous index used to build subset ending at i
        vector<int> hash(n);
        for(int i = 0; i < n; i++)
            hash[i] = i;

        /*************** STEP 4: VARIABLES ************/
        int maxi = 1;        // maximum subset length
        int lastIndex = 0;   // index where max subset ends

        /*************** STEP 5: DP TRANSITION ********/
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {

                // Divisibility condition (LIS-style)
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            // Track maximum length and its ending index
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        /*************** STEP 6: RECONSTRUCTION ********/
        vector<int> res;
        res.push_back(nums[lastIndex]);

        // Walk back using parent pointers
        while(lastIndex != hash[lastIndex]) {
            lastIndex = hash[lastIndex];
            res.push_back(nums[lastIndex]);
        }

        // Reverse because we collected backwards
        reverse(res.begin(), res.end());

        return res;
    }
};

/****************************************************
 * INTUITION SUMMARY (VERY IMPORTANT):
 * ---------------------------------
 * 1. Subset has NO order, but we SORT for DP ease.
 * 2. dp[i] stores the best subset ending at nums[i].
 * 3. We extend subset if nums[i] % nums[j] == 0.
 * 4. hash[] helps reconstruct the actual subset.
 * 5. This is LIS with a different condition.
 *
 * TIME COMPLEXITY:
 * ----------------
 * O(n^2)
 *
 * SPACE COMPLEXITY:
 * -----------------
 * O(n)
 *
 * ONE-LINE MEMORY HOOK:
 * --------------------
 * "LC 368 = LIS where > is replaced by divisible"
 *
 ****************************************************/