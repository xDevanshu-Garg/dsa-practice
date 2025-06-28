#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//! 496. Next Greater Element I: https://leetcode.com/problems/next-greater-element-i/
//This is same as NGE we did earlier but this questions says you have to find NGE's for nums1 which is a subset of num2. So to do this we first find NGE in nums2 and map them with their acctual value like NGE for 2 is -1 like this and then find using map in O(1) time for every element of nums1 in nums2. 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;
        stack<int> st;

        // Finding NGE for nums2 and mapping it with array
        for(int i = nums2.size() -1; i >= 0; i--){
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            if(st.empty()) ngeMap[nums2[i]] = -1;
            else ngeMap[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        //now match ans with array 2
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(ngeMap[nums1[i]]);
        }
        return ans;
    }
};

//! 503. Next Greater Element II: https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n);

        //? ******************************BRUTE FORCE**********************************
        
        bool found = false;
        for(int i = 0; i<n; i++){
            found = false;
            for(int j = i+1; j<n+i; j++){
               if(nums[i] < nums[j%n]) {ans.push_back(nums[j%n]); found = true; break;}
            }
            if(!found) ans.push_back(-1);
        }
        return ans;
        

        //? **************************USING MONOTONIC STACK****************************
        //Here we process extra elements 
        //2n -1 is used because let's say for n-1th element(last) we have already traversed all elements at least once.
        for(int i = 2*n - 1; i >= 0; i--){
            while(!s.empty() && nums[i%n] >= s.top()){
                s.pop();
            }
            //this condition sayd dont mess with stack untill we've travered all the array atleast once
            if(i < n){
                if(s.empty()) ans[i] = -1;
                else ans[i] = s.top();
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};