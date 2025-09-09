#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! 117. Populating Next Right Pointers in Each Node II
//! https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/


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
    Node* connect(Node* root) {
        //Here there is no Perfect BT so we can go for simple LOT
        // Or for interviews here's O(1) soln

        Node* curr = root; //Inital step
        while(curr) { //This loop check for curr that after moving down is curr still valid?
            //2 pointers dummy is to keep track of head of that level and also to provide curr next place to iterate which will we checked by above while loop.
            //tail is to connect all the nodes in next level with next pointers
            Node* dummy = new Node();
            Node* tail = dummy;

            while(curr) { //This loop check for curr in curr level that after moving next is curr still valid?
                //if left exist connect tail with left
                if(curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                //if right exist connect tail with right
                if(curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next; //Move curr in curr level
            }
            curr = dummy->next; //Move curr to next level
        }
        return root;
    }
};