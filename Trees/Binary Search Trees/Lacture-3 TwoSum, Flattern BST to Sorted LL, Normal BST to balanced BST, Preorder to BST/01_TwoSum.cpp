
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//! https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Make a sorted array using inorder traversal then use two pointer approach
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        //Base Case
        if(!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans); //finding inorder so that we can have sorted array

        //By two pointer approach
        int s = 0, e = ans.size()-1;

        while(s < e){
            //Case 1: We've got our ans
            if(ans[s] + ans[e] == k) return true;

            //Case 2: Sum is less then k so move i forward so that value can become big.
            if(ans[s] + ans[e] < k) s++;

            //Case 3: Sum is greator so move e backwards.
            if(ans[s] + ans[e] > k) e--;
        }
        return false;
    }
};