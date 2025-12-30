#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ! https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

//********************NAIVE APPROACH*************************
// TC: O(n^2 logk)
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // Minheap with (value, {row, col})
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            minHeap;

        // 1) Push first element of rows
        for(int i = 0; i < min(n, k); i++)
            minHeap.push({matrix[i][0], {i, 0}});

        // 2) Pop k times and push next element of that row
        for(int i = 0; i < k-1; i++) {
            auto top = minHeap.top();
            int row = top.second.first;
            int col = top.second.second;
            minHeap.pop();

            //push
            if(col + 1 < n) minHeap.push({matrix[row][col+1], {row, col+1}});
        }
        return minHeap.top().first;
    }
};

// Intuition: We're using the property that rows are sorted. 
//Steps: 1. We'll push each row's first element into min heap, so now we know the top of minheap have the first smallest element
// 2. We'll pop k-1 times (means we're removing k-1 smallest element)
//3. But if we directly pop the element then maybe it's neighbour (col+1) element was next smallest element, so we'll pop from top and push col+1 (if exists) into the minHeap.


// Taking example 1: Intital minHeap = 1 10 12

// K-Iterations
// minHeap = [5 10 12]
// 9 10 12
// 10 12
// 11 12
// 12 13
// 13 13
// 13
// 15

// so we'll do k-1 iteration to preserve kth smallest element. 

//Time: O(k log n)
// Space: O(n)
// Much better than naive O(n² log k).

//Optional improvment 
// for(int i = 0; i < min(n, k); i++)
// Because: kth smallest cannot come from more than k rows. We can do this because col are also sorted, now we've used both the properties of this ques.


//Reasoning
//To find k smallest When we don't have a way to pick smallest element among the whole array we use max heap to throw largest elements away and only keep k smallest elements, that way we've kth smallest ele at top of max heap
//But if somehow we surely know smallest element then throw k-1 smallest elements using min heap and then top of min heap is answer. 
// Since arrays were sorted we surly know smallest element so we throw it k-1 times
// Since cols are also sorted so we keep only k sized min heap. 