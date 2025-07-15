#include <iostream>
#include<bits/stdc++.h>
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

// ! https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
/*
Approach 1: For every node ask where should I go should I move to left or right but this will increase or TC to n2 
Appraoch 2: We can find inorder by sorting preorder and then apply the logic make binary tree from inorder and preorder. But sorting will lead to our TC to nlogn
Approach 3: We'll use range method 
    We'll track the range for left it is min to root->val and for right it is root->val to max
    'i' is used as index to traverse our preorder array
    Base Case: i is equals to pre ki size means pre array khtam ho chuka h or pre ka element min se chota h pre ka eleemnt max se bada h to NULL return krdo us node to NULL bana do.
    
*/
class Solution {
public:
    TreeNode* solve(vector<int>& pre, long long min, long long max, int &i) {
        //Base Case
        if(i == pre.size() || pre[i] < min || pre[i] > max) return NULL;

        TreeNode* root = new TreeNode(pre[i++]);
        root->left = solve(pre, min, root->val, i);
        root->right = solve(pre, root->val, max, i);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val); // left bound is implicitly root->val
        root->right = build(preorder, i, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //Using Range
        int i = 0;
        // return solve(preorder, LLONG_MIN, LLONG_MAX, i);
        i = 0;  
        return build(preorder, i, INT_MAX);
    }
};