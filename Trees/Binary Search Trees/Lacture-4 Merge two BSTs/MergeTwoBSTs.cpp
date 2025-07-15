//!https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//Approach 1: Using arrays. Create arrays from inorder -> merge them (merge two sorted arrays) and return TC and SC in O(n) 
class Solution {
  public: 
    void inorder(Node* root, vector<int> &in){
        //Base Case
        if(!root) return;

        inorder(root->left, in);   
        in.push_back(root->data); 
        inorder(root->right, in);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        //Step1: find inorder of both the trees.
        vector<int> firstIn;
        inorder(root1, firstIn);
        
        vector<int> secondIn;
        inorder(root2, secondIn);
        
        // Step2: Merge two sorted arrays.
        vector<int> mergedIn;
        int i = 0, j = 0;
        int n = firstIn.size(), m = secondIn.size();

        while(i < n && j < m){
            if(firstIn[i] < secondIn[j]) mergedIn.push_back(firstIn[i++]);
            else mergedIn.push_back(secondIn[j++]);
        }
        while(i < n) mergedIn.push_back(firstIn[i++]);
        while(j < m) mergedIn.push_back(secondIn[j++]);
        
        // Step3: return our array
        return mergedIn;
        //But if we need to make a tree then just use inorder vector to tree method from prev lacture.
    }
};
// we can optimize SC to O(1) by modifying input tree (only when interviewer asks cuz this will modify input tree)

//Approach 2: Using LL. Create LL from inorder traversal -> merge two sorted LL and return 
class Solution {
  public:
    // Converts BST to sorted right-skewed LL (in-order)
    void bstToLL(Node* root, Node* &prev, Node* &head) {
        if (!root) return;

        bstToLL(root->left, prev, head);

        if (prev) {
            prev->right = root;
            prev->left = NULL;
        } else {
            head = root;  // First node is head of linked list
        }
        prev = root;

        bstToLL(root->right, prev, head);
    }

    // Merge two sorted right-skewed LLs
    Node* mergeLLs(Node* head1, Node* head2) {
        Node dummy(-1);
        Node* tail = &dummy;

        while (head1 && head2) {
            if (head1->data < head2->data) {
                tail->right = head1;
                head1 = head1->right;
            } else {
                tail->right = head2;
                head2 = head2->right;
            }
            tail = tail->right;
            tail->left = NULL;  // Clean up left pointers
        }

        if (head1) tail->right = head1;
        if (head2) tail->right = head2;

        return dummy.right;
    }

    vector<int> merge(Node *root1, Node *root2) {
        // Convert both BSTs into sorted LLs
        Node *head1 = NULL, *prev1 = NULL;
        bstToLL(root1, prev1, head1);

        Node *head2 = NULL, *prev2 = NULL;
        bstToLL(root2, prev2, head2);

        // Merge the two LLs
        Node* mergedHead = mergeLLs(head1, head2);

        // Traverse the merged LL and collect the result
        vector<int> result;
        Node* curr = mergedHead;
        while (curr) {
            result.push_back(curr->data);
            curr = curr->right;
        }
        return result;
    }
};

