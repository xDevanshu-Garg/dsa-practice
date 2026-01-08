#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefixSum = 0, count = 0;
        mp[0] = 1;

        for(int x: nums) {
            prefixSum += x;
            count += mp[prefixSum - k];
            mp[prefixSum]++;
        }
        return count;
    }
};

//Same problem but diff language.

//! https://www.geeksforgeeks.org/problems/count-subarray-with-k-odds/1

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // making odds 1, evens 0, so problem changes to Count subarrays whose sum is exactly k
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = (arr[i] & 1) ? 1 : 0;
        }
        
        int prefixSum = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        for(int x: arr) {
            prefixSum += x;
            count += mp[prefixSum - k];
            mp[prefixSum]++;
        }
        return count;
    }
};

//Single pass
int countSubarraysWithKOdds(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;  // base case

    int prefixSum = 0;
    int count = 0;

    for (int x : arr) {
        // Convert odd to 1, even to 0
        prefixSum += (x % 2);

        if (mp.count(prefixSum - k)) {
            count += mp[prefixSum - k];
        }

        mp[prefixSum]++;
    }

    return count;
}