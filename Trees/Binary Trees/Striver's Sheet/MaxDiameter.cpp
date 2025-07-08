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

// Idea: We'll assign a index to each node. But wait sometimes in between nodes are missing so we'll use a formula. 
// Let's say parent node is at index i so left child is at i*2 + 1 and right i*2+1 (for 0 based indexing)
// So we'll map every node with index starting from root = 0
// Do level order traversal and traverse while storing index using pair inside a queue. And at each level store first and last index and minus them and add 1 and store the max ans. At this point our code is complete.
// For optimization
// At some point our tree will be so big and index will get out of int range so we'll minus front node index of each level from every node of that level and then calc for it's childs. But this is optional.
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    // Stores each node with its "index" as if it were placed in a complete binary tree because then only we can track the diameter 
        queue<pair<TreeNode*, long long>> q;

        // Variables to track the first and last indices of nodes in each level
        long long firstIndex = 0, lastIndex = 0;

        // Variable to store the maximum width across all levels
        int maxWidth = 0;

        // Push the root node with index 0
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

            // Width will be calculated as (lastIndex - firstIndex + 1)
            // To prevent overflow, normalize index by subtracting min index (minn) what it does is takes first index of that level and minus that with remaining nodes in that level so that next level's indexes remain small
            long long minn = q.front().second;

            // Traverse all nodes of the current level
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();

                TreeNode* frontNode = temp.first;

                // Normalize index to prevent overflow (especially for deep trees)
                long long index = temp.second - minn;

                // Store the first and last index for this level
                if (i == 0)
                    firstIndex = index;
                if (i == size - 1)
                    lastIndex = index;

                // If left child exists, assign index as 2 * index + 1
                if (frontNode->left)
                    q.push({frontNode->left, index * 2 + 1});

                // If right child exists, assign index as 2 * index + 2
                if (frontNode->right)
                    q.push({frontNode->right, index * 2 + 2});
            }

            // Compute width of current level and update maxWidth
            int width = lastIndex - firstIndex + 1;
            maxWidth = max(maxWidth, width);
        }

        return maxWidth;
    }
};