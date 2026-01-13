#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int Min = INT_MAX, maxAns = 0, ans = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < Min)
            Min = prices[i]; 
        
        ans = prices[i] - Min;
        if(maxAns < ans) maxAns = ans;
    }
    return maxAns;
    }
};