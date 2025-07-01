#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Next Smaller Element : https://bit.ly/

/* 🔍 Next Smaller Element (to the right)
   Given an array, for each element find the next smaller element to its right.
   If no such element exists, return -1 for that position.

   🔹 Idea:
   - Traverse the array **from right to left**.
   - Use a **monotonic increasing stack** (top always has the next smaller candidate).
   - For every element:
     1. Pop stack while top ≥ current element (not smaller).
     2. Top of the stack is the **next smaller element**.
     3. Push current element to the stack for next iterations.

   🔹 Steps:
   1. Initialize `stack<int> s` with -1 (sentinel for "no smaller element").
   2. Traverse `i = n-1` to `0`:
      - While `s.top() >= arr[i]`: pop from stack, ****jo bade h unhe pop krdo*****
      - `arr[i] = s.top()` (this is the next smaller)
      - Push current element to stack

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(n) for stack

   🧠 Pattern:
   - Monotonic Stack
   - Also used in:
     - Next Greater Element
     - Largest Rectangle in Histogram
     - Daily Temperatures
     - Stock Span
*/


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // ****************************Brute Force**********************************
    
    for(int i = 0; i<arr.size(); i++){
        bool isFound = false;
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] > arr[j]){
                arr[i] = arr[j];
                isFound = true;
                break;
            }
        }
        if(!isFound) arr[i] = -1;
    }
    return arr;
    
    //***************************optimized using stack*************************
    stack<int> s;
    s.push(-1);

    for(int i = n-1; i >= 0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        //ans is stack ka top
        arr[i] = s.top();
        s.push(curr);
    }
    return arr;
}

/* Test Case: 
2 1 4 3
1 3 2
Outputs: 
1 -1 3 -1
-1 2 -1
*/

//!  🔍 Largest Rectangular Area in Histogram
//!   Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
/*
   ✅ Problem:
   Given an array of heights representing histogram bars, find the largest rectangular area under the histogram.

   🔹 Idea:
   - For every bar at index `i`, find:
     - `prevSmaller[i]`: index of the previous smaller element to the left
     - `nextSmaller[i]`: index of the next smaller element to the right
   - The **width** of rectangle = `next[i] - prev[i] - 1` (-1 isiliye kyuki hme inke beech ka chaiye jaise 4 - 1 = 3 pr inke beech 2nd aur 3rd hi aaya pr ans 3 aa rha tha to -1 kiya )
   - The **area** = `height[i] * width`

   🔹 Steps:
   1. Use a **monotonic increasing stack** to find:
      - Previous smaller element indices (left scan)
      - Next smaller element indices (right scan)
   2. For each `i`, calculate area using:  
      `area = height[i] * (next[i] - prev[i] - 1)`
   3. Track the maximum area

   🔹 Edge Handling:
   - If `next[i] == -1`, assume it as `n` (end of histogram)
   - `prev[i]` is initialized as -1 already

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(n) — for stacks and helper arrays

   🧠 Pattern:
   - Monotonic Stack (increasing)
   - Related to:
     - Max Rectangle in Binary Matrix
     - Next/Prev Greater or Smaller Elements
     - Histogram-style subarray area problems
*/

class Solution {
public:
    vector<int> nextSmallerElement(vector<int> next, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        int curr = 0;

        for(int i = n-1; i>=0; i--){
            curr = i;
            while(s.top() != -1 && next[s.top()] >= next[i]){
                s.pop();
            }
            //we have our minimum element's index
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> prev, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            while(s.top() != -1 && prev[s.top()] >= prev[i]){
                s.pop();
            }
            //we have our minimum element's index
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //Creating 2 arrays of next and prev smaller elements
        vector<int> next;
        vector<int> prev;

        next = nextSmallerElement(heights, n);
        prev = prevSmallerElement(heights, n); 
        //Now we want to apply our formula
        int max = 0;
        for(int i = 0; i<n; i++){
            int l = heights[i];
            //This is necessary if next is -1 means it is at n if prev is at -1 means automatically it is at -1
            if(next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            if(area > max) max = area;
        }
        return max;
    }
};

//REvised