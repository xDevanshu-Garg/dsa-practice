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

// ! https://leetcode.com/problems/balance-a-binary-search-tree/

//Simple just find inorder traversal and then apply inorder to BST logic
class Solution {
public:

    void inorder(TreeNode* root, vector<int> &in){
        //Base Case
        if(!root) return;

        inorder(root->left, in);   
        in.push_back(root->val); 
        inorder(root->right, in);
    }

    TreeNode* inorderToBST(vector<int> &in, int s, int e){
        //Base Case
        if(s > e) return NULL;

        int mid = s + (e-s)/2;
        TreeNode* node = new TreeNode(in[mid]);

        node->left = inorderToBST(in, s, mid-1);    
        node->right = inorderToBST(in, mid+1, e);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        //Finding inorder
        vector<int> inorderArray;
        inorder(root, inorderArray);

        //constructing a balanced BST from inorder
        return inorderToBST(inorderArray, 0, inorderArray.size()-1);
    }
};