//! https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        //Step1: Make a min heap and store first K elements.
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < k; i++){
            minHeap.push(nums[i]);
        }

        //Step 2: now after k elements if any element is greater then min heaps's top then we have to sacrifise our smallest element in heap so we can make space of bigger element so pop heap's top and push ele.
        for(int i = k; i < nums.size(); i++){
            if(nums[i] > minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
        */
        
        // short ans
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop(); // Keep only k largest
        }
        return minHeap.top();
    }
};
/*
Tc = O(n logk)
SC = O(k)
    */

