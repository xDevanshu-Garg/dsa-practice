#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Intuition bada h to seedhe push krdo, chota h to uski shi posn dundh kr use replace krdo, kyuki agr chota hoga to LIS ko aage extend krne ke chance zayada honge(Greedy) for better explanation read this code and go to dp 44 comments.

// lower_bound(x)	first >= x
// upper_bound(x)	first > x

// Example: v = {1, 3, 3, 3, 5}

// lower_bound(3) → index 1  
// upper_bound(3) → index 4
// IMPORTANT: "Array must be sorted" And they returns an iterator, so if we want 

// Temp array is not LIS, we're using it just to store elements.
/*
[1, 7, 8, 4, 5, 6, -1, 9]
Dry run: 
temp = [1, 7, 8], but then 4 came and we would have created a new array with [1, 4..] but here we'll override 7 to 4(lowe_bound), to manage space. The temp is still valid.
temp = [1, 4, 8] then [1, 4, 5] then [1, 4, 5, 6] then [-1, 4, 5, 6] then [-1, 4, 5, 6, 9]
we'll not need 7 and 8 in future because we're inserting smaller elements in place of theirs, so agr inke (7 aur 8) ke baad kuch aata bhi to vo 4,5 ke baad aa hi sakta h.

And we don't have to search for lower bound in linear fashion we're using BS because the temp is sorted, we need lower_bound so we gonna use in built STL of c++
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > temp.back()) 
                temp.push_back(nums[i]);
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};