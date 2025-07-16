//! https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        
        for(int ele: arr){
            pq.push(ele);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};