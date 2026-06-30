#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1

// Insight : When we have unique elements LCS becomes LIS

class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int x: nums) {
            if(x > temp.back()) 
                temp.push_back(x);
            else {
                int ind = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
                temp[ind] = x;
            }
        }
        return temp.size();
    }
    
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        int n = a.size(), m = b.size();
        
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++) {
            mp[b[i]] = i;
        }
        
        // Now traverse a
        vector<int> mapped;
        for (int x : a) {
            if (mp.find(x) != mp.end()) {
                mapped.push_back(mp[x]);
            }
        }
        
        // FIND len of LIS
        int k = lengthOfLIS(mapped);
        
        return n - k + m - k;
    }
};

// Approach is find LCS, because then we've to insert less, delete less means overall less operations.
// But LCS cost O(nm) here we cannot afford it, so we've to optmize this, see b is sorted and unique, it means we can do something about b.
// If we map b like {val, ind}, because they're unique so this can be done, then when we traverse a if we found same element as in map we can maintain a new array with indexes of b, then we can find LIS in that array, because LIS will be the longest common subsequence between a and b, because b is sorted and unique.

// For example, b = [1,3,5,7] map = 1 -> 0, 3 -> 1, 5 -> 2, 7 -> 3
    // Now traverse a. And whenever an element exists in b, replace it with its index.
    // a = [1,2,5,3,1] -> [0,2,1,0] (2 is ignored because it isn't in b.)
    // another eg: a = [1,3,7,1,3,5,7] -> [0,1,3,0,1,2,3] now we can find LIS in this array, which is [0,1,2,3] and len = 4, so k = 4
    
// Now simply find LIS in b, then apply this formula n-k + m-k (where k is len of LIS) (n-k how many ele to delete, m-k how many ele needes to be added)