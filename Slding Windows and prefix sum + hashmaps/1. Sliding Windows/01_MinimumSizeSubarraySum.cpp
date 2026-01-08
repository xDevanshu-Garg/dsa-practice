#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Sliding Windows is used when there are only positives in the array, used to find subarrays.

// if we have only positive numbers and we have to find sum k in a subarray where array can be upto 10^9 (Basically solve in O(n)) then we use sliding windows
// Why it works? Because all numbers are positive, increasing the window size only increases the sum, and shrinking it only decreases the sum. This monotonic behavior is the key.
//Trick: 
//   Min: Increase the size of window untill it's valid then decrease the size of winodow untill it's invalid
//   Max: Increase the size of window untill it's invalid then decrease the size of winodow untill it's valid again.

//Stopping condn when right reaches end in max/min. And for exactly type of condn stop when we found exactly k size subarray. 
/*
| Condition                    | Technique        |
| ---------------------------- | ---------------- |
| All positive                 | Sliding Window   |
| Contains negative            | Prefix Sum + Map |
| Min / max window             | Sliding Window   |
| Count subarrays (Exactly K)  | Prefix Sum + Map |
| Count subarrays (At most K)  | Sliding Window   |

*/

//! https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, i = 0, j = 0, mini = INT_MAX;

        while(j < nums.size()) {
            sum += nums[j]; //Build step

            while(sum >= target) { // Valid Window so undo
                mini = min(mini, j-i+1);
                sum -= nums[i]; //Undo step
                i++; //Shrink window
            }
            j++; //Expand window
        }
        return (mini == INT_MAX) ? 0 : mini;
    }
};


//[4, -2, 1] → sum = 3, sliding window will fail here, because of -ves, in this we've to find a subarray with sum exaclty k.