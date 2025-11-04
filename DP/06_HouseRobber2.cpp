#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Link: https://leetcode.com/problems/house-robber-ii/
//? Only Difference is that nums is circular 

//Same just compute max bw array without last element and array without first element, whichever is max is the ans.
//WE modified our ROB fn to accept left and right two pointers so that we don't need to pass subarray because then we have to create 2 subarrays for nums then it'll increase out TC.
class Solution {
public:
    int ROB(vector<int>& nums, int l, int r) {
        int n = nums.size();
        if (l == r) return nums[l]; // only one house in this range

        int prev2 = nums[l];
        int prev = max(nums[l], nums[l+1]);

        for(int i = l+2; i <= r; i++) {
            //Pick
            int pick = nums[i] + prev2;
            //Not-Pick
            int nPick = prev;

            int curr = max(pick, nPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(ROB(nums, 0, n-2), ROB(nums, 1, n-1));
    }
};