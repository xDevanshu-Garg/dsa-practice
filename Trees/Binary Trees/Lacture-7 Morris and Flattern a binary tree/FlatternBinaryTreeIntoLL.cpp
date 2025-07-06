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

// We've to use morris traversal for this because q says you've to do this in o(1) space
// Question says flattern a Binary tree such that it looks like linked list with preorder traversal with all left pointers pointing to NULL and right connected to next nodes.

class Solution {
public:
    /* Algo: if there is no left then no need to change anything go right
            else if left exist then:
                - find predecessor
                    - point pre->right to root->right so in future we can reach
curr's right.
                    - root->right is root->left (break link)
                    - clean left node means root->left = NULL
                    - go to right for furture traversing means root = root->right
    */
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* prev = curr->left;
                while (prev->right) 
                    prev = prev->right;
                    
                // Rewire the connections
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            // Always move to the right whether left exist or not. if left donsn't exist we obviously move to right and in case it exist we did above processing to adjust right pointer now it's time to move to right.
            cout << curr->val << " -> " ;
            curr = curr->right;
        }
        cout << "NULL";
    }
};

int main(){
    // Creating the tree:       1
    //        1
    //       / \
    //      2   5
    //     / \   \
    //    3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution s;
    s.flatten(root);
}