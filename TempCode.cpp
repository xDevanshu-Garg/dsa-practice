#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long maxMul = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if((nums[i] & nums[j]) == 0) {
                    long long prod = nums[i] * nums[j];
                    maxMul = max(maxMul, prod);
                }
            }
        }
        return maxMul;
    }
};