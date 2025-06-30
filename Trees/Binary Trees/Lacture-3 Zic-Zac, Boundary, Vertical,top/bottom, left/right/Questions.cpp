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
        bool leftToRight = true;

        //Base Case
        if(!root) return result;
        
        q.push(root);
        
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

//! Top view: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        queue<pair<Node*, int> > q;
        map<int , int> mapping;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto temp = q.front();
            Node* frontNode = temp.first;
            int HD = temp.second;
            
            q.pop();
            
            if(mapping.find(HD) == mapping.end()) mapping[HD] = frontNode->data;
            
            if(frontNode->left) q.push({frontNode->left, HD-1});
            if(frontNode->right) q.push({frontNode->right, HD+1});
        }
        vector<int> ans;
        for(auto i: mapping)
            ans.push_back(i.second);
        return ans;
    }
};

//! Bottom view: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*, int> > q;
        map<int , int> mapping;
        
        q.push({root, 0});
        
        while(!q.empty()){
            auto temp = q.front();
            Node* frontNode = temp.first;
            int HD = temp.second;
            
            q.pop();
            
            mapping[HD] = frontNode->data;
            
            if(frontNode->left) q.push({frontNode->left, HD-1});
            if(frontNode->right) q.push({frontNode->right, HD+1});
        }
        vector<int> ans;
        for(auto i: mapping)
            ans.push_back(i.second);
        return ans;
    }
};

//! Left view: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

class Solution {
  public:
    void solve(Node *root, int lvl, vector<int> &ans) {
        //Base Case
        if(!root) return;
        
        //processing
        if(ans.size() == lvl) ans.push_back(root->data);
        
        solve(root->left, lvl+1, ans);   
        solve(root->right, lvl+1, ans);   
    }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        solve(root, 0, ans);
        
        return ans;
    }
};

//! Right view: https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1

class Solution {
  public:
    void solve(Node *root, int lvl, vector<int> &ans) {
        //Base Case
        if(!root) return;
        
        //processing
        if (lvl == ans.size()) ans.push_back(root->data);
        
        solve(root->right, lvl+1, ans);   
        solve(root->left, lvl+1, ans);   
    }
    vector<int> rightView(Node *root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};

//! Diagonal view: https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

class Solution {
  public:
    void solve(Node* root, int d, map<int, vector<int>> &diagonals) {
        if (!root) return;

        diagonals[d].push_back(root->data);
        
        // Left child -> next diagonal
        solve(root->left, d + 1, diagonals);

        // Right child -> same diagonal
        solve(root->right, d, diagonals);
    }

    vector<int> diagonal(Node *root) {
        map<int, vector<int>> diagonals;
        vector<int> ans;
        
        solve(root, 0, diagonals);

        for (auto &pair : diagonals) {
            for (int val : pair.second) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
