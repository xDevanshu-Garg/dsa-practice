#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> minSteps(100000, INT_MAX);
        minSteps[start] = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(auto it: arr) {
                int num = (node * it) % 100000;
                if(steps + 1 < minSteps[num]) {
                    minSteps[num] = steps + 1;
                    if(num == end) return minSteps[num];
                    q.push({num, minSteps[num]});
                }
            }
        }
        return -1;
    }
};