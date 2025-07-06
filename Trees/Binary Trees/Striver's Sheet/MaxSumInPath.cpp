#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

/*
Idea: To compute max path we see that only one root can have split ways and that must be the top most root and it will look like upside down V. 

     1
      \ 
       2
      / \ 
     3   4

see this is not a path so only root can be splitted. 

Now what is happening is that at each node we're calculating the max splitting value and store it in a variable say 'maxi' and now we have to return something so we'll return the second option why? because now that recursion call will go up and that node will be new splitting point so we need to give it the best maximum path without splitting that's why we calculate that I have to return so I need my value and I'll return my left or right whichever is maximum.  

So we use DFS to go deep fist and then calculate two things: 
 - 1) Maximum with split! What is it? it's our upside down V so to calculate that we take 3 values root->val + left and right subtree's max path value. And we also check that this split is maximum or our previous one.
 - 2) We calculate max path to left or right which is that I've to include root's value but should I include left or right which path gives me biggest ans? so we just calculate like this root->val + max(leftAns, rightAns) 

We use max(0, solve(...)) to ignore negative paths that would reduce the total sum.
example: 
    10
   / \
  -10 -15
Why we include this so we'll check if left ans is less then 0 why even count so by taking max fron 0 it'll give 0

If you still not understand what's happning check neetcode's video https://www.youtube.com/watch?v=Hr5cWUld4vU&t=1s
*/
// LINK: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 
class Solution {
public:
    int solve(TreeNode* root, int& maxi){
        //Base Case
        if(!root) return 0;

        //DFS calls
        int leftAns = max(0, solve(root->left, maxi));
        int rightAns = max(0, solve(root->right, maxi));

        maxi = max(maxi, root->val + leftAns + rightAns);

        return root->val + max(leftAns, rightAns);
    }
    int maxPathSum(TreeNode* root) {
        int maxWithSplit = INT_MIN;
        solve(root, maxWithSplit);
        return maxWithSplit;
    }
};