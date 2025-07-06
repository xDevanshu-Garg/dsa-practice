#include <iostream>
#include <bits/stdc++.h>
using namespace std;
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

//!  🔍 Sum of Nodes on the Longest Path (Root → Leaf)
//!    Link: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

/*
   ✅ Problem:
   Given a binary tree, return the sum of nodes **on the longest root-to-leaf path**.
   - If multiple paths have the same length, return the one with the **maximum sum**.

   🔹 Idea:
   - Use **DFS (depth-first search)** to explore all root-to-leaf paths.
   - At each node, track:
     1. `len`  → length of current path
     2. `sum`  → sum of current path
   - At each leaf:
     - If it's the **longest path so far**, update `maxLen` and `maxSum`
     - If path length is equal to `maxLen`, update `maxSum` if current `sum` is greater

   🔹 Steps:
   1. Create helper `solve()` with:
      - Current node
      - Current path length and sum
      - **Refs** to `maxLen` and `maxSum`
   2. At base case (i.e., node == NULL):
      - Compare/update `maxLen` and `maxSum`
   3. Recurse on `left` and `right` with updated path length and sum

   🕒 Time Complexity: O(n) — each node visited once  
   💾 Space Complexity: O(h) — recursion stack (height of tree)

   🧠 Pattern:
   - DFS with parameter tracking (like max root-to-leaf sum, height, etc.)
   - Very similar to:
     - Max path sum from root to leaf
     - Longest path in binary tree
     - Leaf with max sum value
*/

class Solution {
  public:
    void solve(Node* root, int len, int sum, int &maxLen, int &maxSum){
        //Base Case
        if (!root) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
            return;
        }
        sum += root->data;
        solve(root->left, len + 1, sum, maxLen, maxSum);
        solve(root->right, len + 1, sum, maxLen, maxSum);

    }
    int sumOfLongRootToLeafPath(Node *root) {
        int maxSum = 0, maxLen = 0;
        solve(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};

//! LCA in Binary Tree
//! Link: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

// Idea is that if we found out target node then come back up if both left and right call have a value then BOOM you've got ur ans.

class Solution {
  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
        //Base Case
        if(!root) return NULL;
        if(root->data == n1 || root->data == n2) return root;
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns && rightAns) return root;
        if(leftAns && !rightAns) return leftAns;
        if(!leftAns && rightAns) return rightAns;
         if(!leftAns && !rightAns) return NULL;
    }
};


//! 🔍 Count All Paths with Sum = K (Root-to-anywhere)
//!    Link: https://www.geeksforgeeks.org/problems/k-sum-paths/1
/* 
   ✅ Problem:
   Count the number of **paths in a binary tree** where the **sum of values = K**.
   - Path can start from **any node**
   - Path must **go downward** (can end at any node)

   🔹 Key Idea:
   - Use **backtracking + path vector**
   - At each node:
     1. Push value to path
     2. Recursively process left & right
     3. Then check **suffixes** of the current path (from end to start)
        → If sum of any suffix == `k` → increment count
     4. Backtrack by popping the node

   🔹 Why from end to start in `path[]`?
   - Because we care about paths that **end at the current node**

   🔹 Steps:
   - Maintain `vector<int> path` during traversal
   - For each node:
     → `path.push_back(node->data)`
     → Recur left and right
     → Check suffix sums from the end
     → `path.pop_back()` (backtracking)

   🕒 Time Complexity: O(n²) in worst case (skewed tree)
   💾 Space Complexity: O(h) for recursion stack

   🔸 Optimization (Alternate): Use **prefix sum + map** to reduce to O(n)

   🧠 Pattern:
   - Root-to-node path tracking
   - Suffix sum check
   - Backtracking in trees
   - Similar to:
     - Path Sum II (Leetcode)
     - Longest path with target sum
     - Root-to-leaf path sum problems
*/


class Solution {
  public:
    void solve(Node *root, int k, int &count, vector<int> &path){
        if(!root) return;
        
        path.push_back(root->data);
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        
        int sum = 0;
        for(int i = path.size()-1; i >= 0; i--){
            sum += path[i];
            if(sum == k) count++;
        }
        path.pop_back();
    }
    
    int sumK(Node *root, int k) {
        int count = 0;
        vector<int> path;
        solve(root, k, count, path);
        return count;
    }
};
//! Kth Ancestor in a Tree
//! Link: http://geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

/* 
Globally decleare an ans veriable 
make solve function where pass root, refrence of k, node 
idea: DFS till we found out our node. if we did return true
      Now our either we find this at right or left if this is the case then write if condition and decrement k before and then check if k == 0 if yes boom it's the k-th ancestor.
Important: It explains good early return 
*/
class Solution {
  public:
  int ans = -1;
    bool solve(Node *root, int &k, int node){
      //Base Case
        if(!root) return false;

        //find the node
        if(root->data == node) return true;
        
        //Recursion calls
        bool leftAns = solve(root->left, k, node);
        bool rightAns = solve(root->right, k, node);
        
        
        if(leftAns || rightAns) {
            k--;
            if(k == 0){
                ans = root->data;
                return false; //Stop further backtraking
            }
            return true;
        }
        return false;
    }
    
    int kthAncestor(Node *root, int k, int node) {
        solve(root, k, node);
        return ans;
    }
};

//!  🔍 Max Sum of Non-Adjacent Nodes (Tree DP)
//!    Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

/*
   ✅ Problem:
   Find the maximum sum of nodes such that **no two adjacent nodes** (i.e., parent-child) are selected.

   🔹 Why Level Order of Alternate Levels Fails:
   → It's not about levels — it's about **adjacency**  
   ✘ Example:
           20
          /  \
        10    1000
        /
      2000
   - Optimal = 1000 + 2000 = 3000 (but alternate level gives only 2020)

   🔹 Idea:
   - Use **Dynamic Programming on Trees** with **inclusion-exclusion** principle
   - At each node, return a pair:
     1. `first`  → max sum **including** current node
     2. `second` → max sum **excluding** current node

   🔹 Transition:
   - If we **include** current node:
     → We can't include children  
     → So: `root->data + left.second + right.second`

   - If we **exclude** current node:
     → We can choose to include/exclude children  
     → So: `max(left.first, left.second) + max(right.first, right.second)`

   🔹 Steps:
   1. Recursively call for left and right subtree
   2. At each return, compute both include and exclude
   3. Final answer = `max(include, exclude)`

   🕒 Time Complexity: O(n)
   💾 Space Complexity: O(h) (recursion stack)

   🧠 Pattern:
   - Tree DP with inclusion/exclusion
   - Similar to:
     - Max sum in array with no adjacent elements (House Robber)
     - Rob houses in a binary tree (Leetcode Tree version of House Robber)
*/

class Solution {
  public:
    // Doing with inclusion exclusion
    
    pair<int, int> solve(Node* root){
        if(!root) return {0,0};
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> ans;        
        ans.first = root->data + left.second + right.second;
        ans.second = max(left.first, left.second) + max(right.first, right.second);
        
        return ans;
    }
    
    int getMaxSum(Node *root) {
        pair<int,int> ans;
        ans = solve(root);
        
        return max(ans.first, ans.second);
    }
};
