#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/

// To understand this go to part 1 of this ques, and for part 2 think about how sliding windows will help, then what data structure will you use.

// Heaps don't allow iteration and we need to iterate so that we can get minimum k elements so we'll use set, but normal set removes dups, but we need dups, so we'll use multiset, it's ordered and can contain dups as well.

// ms.erase(nums[i-1]) erases all occ of that ele so first find the iterator then erase

// Making 2 ms, small contains k-1 small elements, large contains rest of the eles of window

//*prev(small.end()) is the same value as *small.rbegin()
class Solution {
private:
    // Small stores exactly k-1 elements, all small k-1 elements of a window is inside small, so ovbiously biggest ele inside small is still smaller then smallest ele in large. This is done so that we can access sum in logn time for each window.
    int need;
    multiset<int> small, large;
    long long sumSmall = 0;

    void rebalance() {
        // Small too big
        while(small.size() > need) {
            auto it = prev(small.end());
            sumSmall -= *it;
            large.insert(*it);
            small.erase(it);
        }

        // Small too small (used after deletion)
        while(small.size() < need && !large.empty()) {
            auto it = large.begin();
            sumSmall += *it;
            small.insert(*it);
            large.erase(it);
        }
    }

    void add(int x) {
        small.insert(x);
        sumSmall += x;
        rebalance();
    }

    void remove(int x) {
        auto it = small.find(x);
        if (it != small.end()) {
            sumSmall -= *it;
            small.erase(it);
        } else {
            auto it2 = large.find(x);
            large.erase(it2);
        }
        rebalance();
    }

public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        need = k-1;
        // Initial window push
        for(int i = 0; i <= dist; i++) {
            add(nums[i]);
        }

        long long mini = LLONG_MAX;
        for(int i = 1; i < n-dist; i++) {
            // correct the sliding window
            remove(nums[i-1]);
            add(nums[i+dist]);

            mini = min(mini, sumSmall);
        }
        return nums[0] + mini;
    }
};