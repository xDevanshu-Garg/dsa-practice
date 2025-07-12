#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

//! Search in BST: https://leetcode.com/problems/search-in-a-binary-search-tree/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // //Base Case
        // if(!root) return NULL;

        // if(val == root->val) return root;

        // if(val < root->val)
        //     root = searchBST(root->left, val);
        // else
        //     root = searchBST(root->right, val);
        // return root;
// *******************Good but let's optimize SC with iterative way ***************

        while(root){
            if(val == root->val) return root;

            if(val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return NULL;
    }
};

//! Kth Smallest element in BST : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, int k, int &count) {
        //Base Case
        if(!root) return;
        
        if (count >= k) return; // Early stop once k-th is found

        solve(root->left, k , count);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        //Sare left childs khatm ho gye to right chle jao
        solve(root->right, k , count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        solve(root, k , count);
        return ans;
    }
    //For Kth largest just use this formula size-k+1
    // let's say we've to find 1st largest element so in other words we have to find last smallest element and so on.
    // And for SC to be O(1) we can use Morris traversal.
};

//! Validate BST :https://leetcode.com/problems/validate-binary-search-tree/description/
//Range wise check kro 
class Solution {
public:
    bool solve(TreeNode* root, long long min, long long max) {
        //Base Case
        if(!root) return true;

        if (min < root->val && root->val < max){
            // Only check right subtree if left subtree is valid for optimization ;)
            if (!solve(root->left, min, root->val)) return false;
            return solve(root->right, root->val, max);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

//! Lowest Common Ancestor: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//We'll use BST property as follows:
class Solution{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //There are only 3 cases possible
        while(root){
            // Case 1: Both p and q are in left subtree
            if(p->val < root->val && q->val < root->val)
            root = root->left;
            // Case 2: Both p and q are in right subtree
            if(p->val > root->val && q->val > root->val)
            root = root->right;
            // Case 3: p and q are in different subtree meaning root is the ans
            if((p->val <= root->val && q->val >= root->val) ||
                (p->val >= root->val && q->val <= root->val))
                return root;
        }
        return nullptr;
    }
}; 

//!  Predecessor And Successor In BST: https://www.naukri.com/code360/problems/predecessor-and-successor-in-bst_893049
//Predecessor: Inorder me node ke just phle wala element or node ke left subtree me sabse bada mtlb sabse right
//Successor: Inorder me node ke just baad wala or node ke right subtree me sabse chota mtlb sabse left
/*
We've to track potential pre and suc both because let's say in case of this tree
   3
  / 
 2
for 2 our pre is NULL kyuki isse chota nhi h and suc is 3 just bada wahi h
mtlb zaruri nhi h ki suc hamesha root ke right me jake hi milega uper bhi to ho sakta h uska successor lekin agr hm track hi nhi rakhte to NULL return krte jo ki glt ho jata. Han agr tree hi 2 hota mtlb q esa kehta ki jo apni key h bas udher se tree start hota h uper ka bhool jao to NULL ans ho jata pr is case me esa nhi tha.
*/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode* temp = root;
    TreeNode* pred = NULL;
    TreeNode* succ = NULL;

    // Step 1: Find the key while keeping track of possible successor and predecessor
    while (temp && temp->val != key) {
        if (key < temp->val) {
            //key choti h mtlb root bada h to ab hm usse ek chote pr jayenge to root to hamari potential succ ho sakta h 
            succ = temp;  // Possible successor
            temp = temp->left;
        } else {
            pred = temp;  // Possible predecessor
            temp = temp->right;
        }
    }

    // Early return if Key not found
    if (!temp) return {pred ? pred->val : -1, succ ? succ->val : -1};

    
    // Step 2: Find predecessor (max in left subtree)
    if (temp->left) {
        TreeNode* leftSub = temp->left;
        while (leftSub->right) leftSub = leftSub->right;
        pred = leftSub;
    }

    // Step 3: Find successor (min in right subtree)
    if (temp->right) {
        TreeNode* rightSub = temp->right;
        while (rightSub->left) rightSub = rightSub->left;
        succ = rightSub;
    }

    return {pred ? pred->val : -1, succ ? succ->val : -1};

}