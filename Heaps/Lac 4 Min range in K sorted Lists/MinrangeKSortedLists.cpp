//! https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
//TC: O(NlogK) where N is the total number of elements across all lists and K is the number of lists.
//SC: O(K) for the min heap
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    int i; // list index
    int j; // element index in list

    node(int val, int row, int col) {
        data = val;
        i = row;
        j = col;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node*, vector<node*>, compare> minHeap;

        int maxi = INT_MIN;
        int range = INT_MAX, ansMin = -1, ansMax = -1;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i][0];
            minHeap.push(new node(val, i, 0));
            maxi = max(maxi, val);
        }


        while (!minHeap.empty()) {
            node* top = minHeap.top();
            minHeap.pop();

            int mini = top->data;

            if (maxi - mini < range) {
                range = maxi - mini;
                ansMin = mini;
                ansMax = maxi;
            }

            int row = top->i;
            int col = top->j;

            // If more elements are left in the same list
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                maxi = max(maxi, nextVal);
                minHeap.push(new node(nextVal, row, col + 1));
            } else
                break; // one list got exhausted so break otherwise our heap will be less then of size k cuz an element is already poped but new element is not added
        }

        return {ansMin, ansMax};
    }
};
