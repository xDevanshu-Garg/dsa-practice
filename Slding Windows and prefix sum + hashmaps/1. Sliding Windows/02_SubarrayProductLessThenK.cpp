#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/subarray-product-less-than-k/description/
//count, less then(At most)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; //Integers can't have product less then 1

        int i = 0, j = 0, count = 0;
        long long prod = 1;

        while(j < nums.size()) { //stopping condn
            prod *= nums[j]; //Build step
            j++;

            while(prod >= k) { //Valid window
                prod /= nums[i]; //Undo
                i++;
            }

            count += j - i;
            //for each j all subarrays are valid: [i..j], [i+1..j], ..., [j..j]
        }
        return count;
    }
};