#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//!  🔍 Height of Binary Tree
//!   Link: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

   /*
   ✅ Problem:
   Given the root of a binary tree, return the height of the tree.

   🔹 Idea:
   - Use recursion (post-order traversal)
   - For each node:
     1. Recursively get height of left and right subtree
     2. Height of current = 1 + max(left, right)

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(h) → height of the tree (stack space) O(n) for skewed tree(height == nodes)

   🧠 Pattern:
   - Classic **post-order recursion**
   - Very common in:
     - Diameter of tree
     - Balanced tree check
*/

class Solution {
public:
    int height(Node* node) {
        if (!node) return 0;  // base case: height of null is -1 edge-wise
        return 1 + max(height(node->left), height(node->right));
    }
};

//! 🔍 Balanced Tree or Not
//! Link: https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

//? *****************************************BRUTE FORCE***********************************************************
class Solution {
  public:
    int height(Node* node) {
        if (!node) return -1;  // base case: height of null is -1 edge-wise
        return 1 + max(height(node->left), height(node->right));
    }
    
    bool isBalanced(Node* root) {
        if(!root) return true;
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left && right && diff) return true;
        return false;
    }
};

//? *************************************OPTIMAL SOLUTION USING PAIR**********************************************
class Solution {
  public:
    pair<bool, int> isBalancedFast(Node* root){
        // Base case: an empty tree is balanced with height 0
        if(!root) return {true, 0};
        
        // Recursively check left and right subtrees otherwise it will only check for root node but a tree can be unbalanced from root, left, right i.e. we have to check for **every node**. 
        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);
        
        // Check the height difference
        bool diff = abs(left.second - right.second) <= 1;
        
        // Current node's height so that we can return it
        int height = max(left.second, right.second) + 1;
        // If left and right are balanced and current node satisfies diff condition
        if(left.first && right.first && diff) return {true, height};
        return {false, height};
    }
    
    bool isBalanced(Node* root) {
        return isBalancedFast(root).first;
    }
};

//* TC: reduced from O(N^2) ot O(N)

//!  🔍 Diameter of Binary Tree
//!    Link: https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Solution {
    pair<int, int> diameterFast(Node* root){
        //Base Case
        if(!root){
            // return make_pair(0, 0)
            //Or
            return {0,0};
        }
        //Recursively call left and right to compute diameter and height respectively without this it will only count for root but we don't want this max diameter can be reached on either side or root so 3 options
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        
        // Options for diameter
        int op1 = left.first;                     // diameter from left subtree
        int op2 = right.first;                    // diameter from right subtree
        int op3 = left.second + right.second + 1; // diameter through root (edges)

        pair<int, int> ans;
        //Since we have 3 options of diameter we'll take maximum once
        ans.first = max(op1, max(op2, op3));
        
        // We're calc height because it's used in option no. 3
        ans.second = max(left.second, right.second) + 1; 
        return ans;
    }
  public:
  
    int diameter(Node* root) {
        return diameterFast(root).first -1;
    }
};


//! 🔍 Check if Two Binary Trees are Identical
//!    Link: https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
/* 
   ✅ Problem:
   Given two binary trees, check whether they are structurally identical and have the same node values.

   🔹 Idea:
   - For each node pair (r1, r2):
     1. If both are NULL → return true
     2. If only one is NULL → return false
     3. Check:
        - r1->data == r2->data
        - Left subtrees are identical
        - Right subtrees are identical

   🧠 Pattern:
   - Post-order structural comparison
   - Very common in:
     - Subtree check
     - Mirror check (just switch direction)
     - Tree serialization
*/

class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        //Base Case
        if(!r1 && !r2) return true;
        if(r1 && !r2) return false;
        if(!r1 && r2) return false;
        
        //When both are non null then check if both are equal or not
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        //return and check all three conditions that left, right, data should be equal
        return (left && right && r1->data == r2->data);
        
//* If both trees are the same size and balanced then height = logn, so: Time: O(n) worst O(n*m), Space: O(log n) worst O(n) 
    }
};
//! 🔍Sum Tree or Not 
//! Link: https://www.geeksforgeeks.org/problems/sum-tree/1
/*
   ✅ Problem:
   A tree is a **Sum Tree** if the value of every non-leaf node is equal to the **sum of the values in its left and right subtrees**.

   🔹 Rules:
   - Leaf nodes are considered Sum Trees.
   - Empty trees are also Sum Trees with sum = 0.

   🔹 Idea:
   - Use **post-order traversal** (process children first).
   - Return a `pair<bool, int>`:
     1. `bool`: whether the subtree is a Sum Tree
     2. `int`: sum of subtree (to validate parent node)

   🔹 Steps:
   1. Base case:
      - NULL → `{true, 0}`
      - Leaf → `{true, node->data}`
   2. Recursively check left and right
   3. Check:
      - If both left/right are Sum Trees **and**
      - Current node’s value = leftSum + rightSum
   4. If yes → return `{true, 2 * node->data}`
      (because sum = left + right + node->data = 2 * node->data)

   🔸 Final return: `isSumTreeFast(root).first`

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(h) (due to recursion stack)

   🧠 Pattern:
   - Post-order with multiple returns
   - Similar to:
     - Diameter of Tree
     - Max Path Sum
     - Balanced Tree Check
*/

class Solution {
  public:
    //bool: whether the subtree is a Sum Tree and int: to store total sum 
    pair<bool, int> isSumTreeFast(Node* root) {
        // Base Case: Empty tree is a sum tree with sum 0
        if (!root) return {true, 0};

        // Leaf node is also a sum tree with its own data
        if (!root->left && !root->right) return {true, root->data};

        // Recursive calls for left and right subtrees
        pair<bool, int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);

        int sum = left.second + right.second;

        // If left and right are sum trees and current node follows sum tree property
        if (left.first && right.first && root->data == sum) {
            return {true, 2*sum}; // Or root->data + sum is also valid
        }

        return {false, 0}; // Not a sum tree
    }

    bool isSumTree(Node* root) {
        return isSumTreeFast(root).first;
    }

};