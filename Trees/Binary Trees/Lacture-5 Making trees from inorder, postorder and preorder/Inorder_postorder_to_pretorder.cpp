//! Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
//! 🔍 Construct Binary Tree from Inorder & Postorder Traversal

/* 
//* **************************************diff things**************************
4 things are diff:
postOrderIndex is initalized from n-1
postOrderIndex is used to make root and then decrement it
base case is diff which is postorderIndex < 0 and second base case is same
right child recursion is called first and then for left child

   ✅ Problem:
   Given inorder and postorder traversal of a binary tree, construct the original tree.

   🔹 Traversal Rules:
   - Inorder:    Left → Root → Right
   - Postorder:  Left → Right → Root

   🔹 Key Idea:
   1. Use `postorderIndex` to pick the **current root** from `postorder[]` (starting from the end)
   2. Find this root in `inorder[]` using a hash map
   3. Recursively build:
      - Right subtree first (because we're moving backward in postorder)
      - Then left subtree

   🔹 Why right first?
   - In postorder (Left, Right, Root), the **last element** is root
   - The element before root is **right child**, so we must build the right subtree first

   🔹 Steps:
   - Create a `map<int, int>` from inorder values for O(1) lookup
   - Initialize `postorderIndex = postorder.size() - 1`
   - In the recursive function:
     → Create root from `postorder[postorderIndex--]`  
     → Find root index in inorder[]  
     → Recur for right & left subtree using updated bounds

   🔹 Base Case:
   - If `postorderIndex < 0` or `inorderStart > inorderEnd` → return NULL

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(n) — hash map + recursion stack

   🧠 Pattern:
   - Divide and conquer using traversal arrays
   - Just like:
     - Inorder + Preorder → Build tree (but left subtree is built first)
     - Inorder + Levelorder → Extra tricky (needs queue/level-wise logic)
*/

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:

    void preOrderTraversal(Node* root){
        Node* temp = root;
        if(temp == NULL) return;

        cout << temp->data << " ";
        preOrderTraversal(temp->left);
        preOrderTraversal(temp->right);
    }

    Node* solve(vector<int> &inorder, vector<int> &postorder, int &postorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &inorderIndex){
        
        //Base case
        if(postorderIndex < 0 || inorderStart > inorderEnd) return NULL;
        
        //Find out the index from preorder and increment it for later
        int ele = postorder[postorderIndex--];
        Node* root = new Node(ele);
        
        //Now let's find ele in inorder so we can recursively call using that
        int posn = inorderIndex[ele];
        
        root->right = solve(inorder, postorder, postorderIndex, posn+1, inorderEnd, inorderIndex);
        root->left = solve(inorder, postorder, postorderIndex, inorderStart, posn-1, inorderIndex);
        
        return root;
    }
    
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        
        // Build map of inorder values
        unordered_map<int, int> inorderIndex;
        for(int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;
        
        int postorderIndex = postorder.size()-1;
        Node* ans = solve(inorder, postorder, postorderIndex, 0, inorder.size()-1, inorderIndex);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};
    Node* ans = s.buildTree(inorder, postorder);
    s.preOrderTraversal(ans);
}