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

void preOrder(Node* root){
    //Store curr so it's not lost
    Node* curr = root;
    //while curr not null. it'll only be null if right side won't exists and if it is the case out tree is traversed.
    while(curr != NULL){
        //mtlb left h hi nhi ya to processed ho gya h to inorder ke hisab se ab root ko print krao aur curr ko right shift krdo
        if(curr->left == NULL){
            cout << curr->data << ' ';
            curr = curr->right;
        }
        //left exists!
        else{
            // But if we go directly to left then we will have no way to come back up so, we'll create a backup. What is backup? we'll create a node called prev and go to the right untill we can from our left node and link that with our curr so when we processed our left node we can come back up ezz.
            Node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            //  But wait when we come back again to curr how do we know if we've processed left or not? simple!! if our prev is NULL means we've to visit left so let's go to left and make sure to link prev to curr so we can come back up.
            if(prev->right == NULL){
                cout << curr->data << ' ';
                prev->right = curr;
                curr = curr->left;
            }
            // But if our prev is already connected to curr that means in past we visited left so no need to process it again we can print our curr node and move to right.
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

int main()
{
    // Creating the tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Morris Inorder Traversal: ";
    preOrder(root); // Expected: 4 2 5 1 3

    return 0;
}
