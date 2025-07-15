//!  🔍 Largest BST Subtree in a Binary Tree
//!    Link: https://www.geeksforgeeks.org/problems/largest-bst/1
/*
   ✅ Problem:
   Return the size of the largest **subtree** that is a **BST** in the given Binary Tree.

   🔹 Idea:
   Use **post-order traversal** to collect info from left and right subtree.
   At each node, calculate whether the current subtree is a BST, and if yes, its size.

   🔸 Create a helper class `info`:
   - `maxi` → Max value in subtree
   - `mini` → Min value in subtree
   - `isBST` → Is this subtree a BST?
   - `size` → Total nodes in this subtree

   🔹 Base Case:
   - If node is NULL, treat it as a BST of size 0 with:
     `maxi = INT_MIN`, `mini = INT_MAX`, `isBST = true`, `size = 0`

   🔹 For each node:
   1. Recursively get `info` from left and right child
   2. Check if current node forms a BST:
      → `left.isBST && right.isBST && left.maxi < root->data && root->data < right.mini`
   3. If true:
      → `isBST = true`, `size = left.size + right.size + 1`
      → Update max answer
   4. Else:
      → `isBST = false`

   🕒 Time Complexity: O(n)  
   💾 Space Complexity: O(h) recursion stack

   🧠 Pattern:
   - Post-order traversal
   - Tree DP or bottom-up recursion
   - Similar to:
     - Validate BST
     - Size of largest subtree
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class info {
  public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

class Solution {
  public:
  
    info solve(Node* root, int &ans){
        //Base Case: Leaf Node is a BST
        if(!root) return {INT_MIN, INT_MAX, true, 0};
        
        info left = solve(root->left, ans);
        info right =  solve(root->right, ans);
        
        info currNode;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);
        
        if(left.isBST && right.isBST && left.maxi < root->data && root->data < right.mini)
            currNode.isBST = true;
        else currNode.isBST = false;
        
        currNode.size = left.size + right.size + 1;
        
        //Update the ans if rot is a BST
        if(currNode.isBST) ans = max(ans, currNode.size);
        
        return currNode;
    }
  
    int largestBst(Node *root) {
        int maxSize = 0;
        solve(root, maxSize);
        return maxSize;
    }
};