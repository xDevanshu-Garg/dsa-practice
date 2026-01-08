#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/max-consecutive-ones-iii/description/
//Max so you know what to do.

class Solution {
public:
//only worry about k when it's -1 (i.e. we've picked a 0 now we've to remove a 0), so ignore 1 and remove 0 while k < 0, when we find 0, just remove it by incrementing k.
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0) {
                k--;
            }
            while(k < 0) {
                if(nums[left] == 0) k++;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};