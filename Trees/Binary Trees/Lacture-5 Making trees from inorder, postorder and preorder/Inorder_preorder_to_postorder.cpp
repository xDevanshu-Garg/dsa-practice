//! 🔍 Construct Binary Tree from Inorder & Preorder Traversal
//! Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

/* 
   ✅ Problem:
   Given preorder and inorder traversal of a binary tree, construct the tree.

   🔹 Traversal Rules:
   - Preorder: Root → Left → Right
   - Inorder: Left → Root → Right

   🔹 Idea:
   1. Use `preOrderIndex` to pick the **next root** from `preorder[]`
   2. Find the root in `inorder[]` using a hash map
   3. Recursively build:
      - Left subtree → from `inOrderStart` to `posn-1`
      - Right subtree → from `posn+1` to `inOrderEnd`

   🔹 Why hash map?
   - To get index of any element in inorder[] in O(1) time

   🔹 Steps:
   - Build `inorderIndex` map: {value → index} using for loop
   - Call helper `solve(...)` with:
     → both the arrays
     → current preorder index  
     → inorder range [start...end]
     → map
   - Increment `preOrderIndex` after creating a root
   - Recursively attach `left` and `right` subtrees

   🔹 Base Case:
   - If `preOrderIndex` goes out of bounds or inOrderStart > inOrderEnd → return NULL

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(n) (due to hashmap + recursion stack)

   🧠 Pattern:
   - Divide-and-conquer using traversal segments
   - Similar approach works for:
     - Inorder + Postorder reconstruction
     - Preorder + Inorder for expression trees
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
    int find(vector<int> &inorder, int ele){
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == ele) return i;
        }
        return -1;
    }
    
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &preOrderIndex, int inOrderStart, int inOrderEnd, unordered_map<int, int> &inorderIndex){
        //Base Case
        if(preOrderIndex > preorder.size() - 1 || inOrderStart > inOrderEnd) return NULL;
        
        //Find out the index from preorder and increment it for later
        int ele = preorder[preOrderIndex++];
        
        //Make root node out of it
        Node* root = new Node(ele);
        
        //Find ele in inorder
        int posn = inorderIndex[ele];
        
        //Recursive calls
        root->left = solve(inorder, preorder, preOrderIndex, inOrderStart, posn-1, inorderIndex);
        root->right = solve(inorder, preorder, preOrderIndex, posn+1, inOrderEnd, inorderIndex);
    
        return root;
    }

    void postOrderTraversal(Node* root){
        Node* temp = root;
        if(temp == NULL) return;

        postOrderTraversal(temp->left);
        postOrderTraversal(temp->right);
        cout << temp->data << " ";
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preOrderIndex = 0;
        int inOrderStart= 0;
        int inOrderEnd = inorder.size() - 1;

        unordered_map<int, int> inorderIndex;
        // Build map of inorder values
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        Node* ans = solve(inorder, preorder, preOrderIndex, inOrderStart, inOrderEnd, inorderIndex);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> inorder = {1, 6, 8, 7};
    vector<int> preorder = {1, 6, 7, 8};
    Node* ans = s.buildTree(inorder, preorder);
    s.postOrderTraversal(ans);
}
