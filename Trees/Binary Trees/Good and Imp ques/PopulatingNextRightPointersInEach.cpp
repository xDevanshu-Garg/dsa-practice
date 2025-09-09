#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! 116. Populating Next Right Pointers in Each Node
// ! https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



class Solution {
public:
//Doing Level order Traversal
    Node* connect(Node* root) {
        if(!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            Node* prev = NULL;
            for(int i = 0; i < n; i++) {
                auto curr = q.front(); q.pop();

                if(prev) prev->next = curr;
                prev = curr;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return root;
    }
};

//TC is O(n) and SC O(n) for queue

/*
there exists a O(1) SC soln 
at each node connect it's left child->next to it's right child.
and if node's next exists then connect node->right->next to node->next->left

then we've to move level by level so if node->next exist move there node = node->next

also save leftMost node because we've to come back there later for next level
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        Node* leftmost = root;

        while(leftmost->left) { // until we reach the last level
            Node* curr = leftmost;

            while(curr) {
                // Connect left -> right
                curr->left->next = curr->right;

                // Connect right -> next->left (if exists)
                if(curr->next)
                    curr->right->next = curr->next->left;

                curr = curr->next; // move horizontally
            }

            leftmost = leftmost->left; // move down
        }

        return root;
    }
};