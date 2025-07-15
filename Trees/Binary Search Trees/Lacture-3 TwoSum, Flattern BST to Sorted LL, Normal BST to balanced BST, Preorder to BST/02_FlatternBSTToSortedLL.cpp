#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//! 🔍 Flatten BST to Sorted Linked List (Right Skewed Tree)
//!   Link: https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

/*
   ✅ Problem:
   Convert a BST into a **sorted right-skewed linked list**
   (i.e., only use `right` pointers to form a list in increasing order, `left` should be NULL)

   🔹 Idea:
   Use **in-order traversal** because:
   - In-order traversal of BST gives **sorted order**
   - But ther's a problem we've to link old elements to root so we'll use a pointer called 'prev'
   
   🔸 Steps:
   1. Traverse `left` subtree
   2. For each node:
      - If `prev` exists:  
        → `prev->right = current`
        → `prev->left = NULL`
      - Else: mark this node as `newRoot` starting me sare left jane wale newRoot ban jayenge pr jaise hi base case hit hoga asli wala newRoot mil jayega aur fir kabhi else me nhi aayenge
      
      - Move `prev` to current node
   3. Traverse `right` subtree
   4. At end, ensure `prev->left = NULL` (last node cleanup)

   📦 Variables:
   - `prev` → pointer to the previous visited node
   - `newRoot` → start of the new linked list

   🕒 Time Complexity: O(n) (visit every node once)
   💾 Space Complexity: O(h) (recursion stack for in-order traversal)

   🧠 Pattern:
   - In-order traversal with external linking
   - Applies in tree-to-LL conversion problems
*/

class Solution {
  public:
    Node* newRoot = NULL;
    
    void solve(Node* root, Node* &prev){
        //Base Case
        if(!root) return;
        
        solve(root->left, prev);
        
        if(prev){
            prev->right = root;
            prev->left = NULL;
        }
        else newRoot = root;
        
        prev = root;
        
        solve(root->right, prev);
    }
    
    Node *flattenBST(Node *root) {
        Node* prev = NULL;
        solve(root, prev);
        //We've to make sure last node's left is set null 
        prev->left = NULL;
        return newRoot;
    }
};