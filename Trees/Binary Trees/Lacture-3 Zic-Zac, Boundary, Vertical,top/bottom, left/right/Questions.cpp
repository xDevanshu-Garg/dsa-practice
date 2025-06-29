#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//! ZigZag Traversal: https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

/*
    1. Do level order traversal and maintain a veriable leftToRight
    2. Everytime alternate leftToRight. (leftToRight = !leftToRight)
    3. if leftToRight is true then store that level in orignal order otherwise store it in reverse in a temp vector
    4. append the result into final ans1
*/
class Solution {
    public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);
            
            for(int i = 0; i < size; i++){
                Node* temp = q.front();
                q.pop();
                
                int index = leftToRight? i : size - i - 1;
                ans[index] = temp->data;
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            leftToRight = !leftToRight;
            for(auto i : ans) result.push_back(i);
        }
        return result;
    }
};

//! Boundary Traversal: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/*
Store root
 1. Traverse left subtree and while going left store the values
 2.1 Traverse leaf nodes of left subtree
 2.2 Traverse leaf nodes of right subtree
 2.3 Traverse right subtree and while coming back store the values.
*/
    class Solution {
      public:
        void solveLeft(Node* root, vector<int> &ans){
            if(!root || !root->left && !root->right) return;
            
            ans.push_back(root->data);
            if(root->left) solveLeft(root->left, ans);
            else solveLeft(root->right, ans);
        }
        void solveLeaf(Node* root, vector<int> &ans){
            if(!root) return;
            if(!root->left && !root->right) ans.push_back(root->data);
            
            //We've to use LNR inorder
            solveLeaf(root->left, ans);
            solveLeaf(root->right, ans);
            
        }
        
        void solveRight(Node* root, vector<int> &ans){
            if(!root || !root->left && !root->right) return;
            
            if(root->right)solveRight(root->right, ans);
            else solveRight(root->left, ans);
            
            ans.push_back(root->data);
        }
        
        vector<int> boundaryTraversal(Node *root) {
            vector<int> ans;
            ans.push_back(root->data);
            solveLeft(root->left, ans);
            solveLeaf(root->left, ans);
            solveLeaf(root->right, ans);
            solveRight(root->right, ans);
            
            
            return ans;
        }
    };