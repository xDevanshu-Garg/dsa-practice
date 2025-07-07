#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

class Solution {
public:
    //Just like level order but use stack and call right first then left
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* frontNode = s.top();
            s.pop();
            ans.push_back(frontNode->val);
            if(frontNode->right) s.push(frontNode->right);
            if(frontNode->left) s.push(frontNode->left);
        }
        return ans;
    }

    //left jate jao(while) aur stack me store krate jao jaise hi null aaye print kra do stack ke top ko. aur ek baar right mud jao fir sab repeat kro
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr || !s.empty()) {
            // Step 1: Reach the leftmost node of the current node
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            // Step 2: Current is NULL at this point
            curr = s.top();
            s.pop();

            ans.push_back(curr->val); // Visit node

            // Step 3: Visit the right subtree
            curr = curr->right;
        }
        return ans;
    }
    

};

int main()
{
    

    return 0;
} 