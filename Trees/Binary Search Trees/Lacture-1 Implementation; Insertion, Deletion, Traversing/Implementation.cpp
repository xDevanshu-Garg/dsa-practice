// Time complexity for unbalanced BST is o(n) in worst cases like skewed trees and if it's balanced then it'll take O(logn) time

//Inorder of BST is sorted

//Inorder Successor: See in lacture -2
//Inorder Predecessor: 

// Min value at BST is at atmost left leaft node and Max value at atmost right node.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    //Base Case
    if(!root){
        root = new Node(data);
        return root;
    }

    if(data < root->data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);
    
    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    //insert data untill it's -1
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            //above we encounter temp = NULL which means we've travered a level already so checking q is not empty means jo level traverse ho chuka h kya usme childs the agr the to unke baad null laga do
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->data <<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void inorder(Node* root){
    Node* temp = root;
    if(temp == NULL) return;

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

void preorder(Node* root){
    Node* temp = root;
    if(temp == NULL) return;

    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(Node* root){
    Node* temp = root;
    if(temp == NULL) return;

    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}

int minVal(Node* root){
    while(root->left)
        root = root->left;
    return root->data;
}
int maxVal(Node* root){
    while(root->right)
        root = root->right;
    return root->data;
}

Node* deleteFromBST(Node* root, int val){
    // Base Case
    if (!root) return NULL;

    if (root->data == val) {
        // Case 1: 0 children (leaf node)
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // Case 2: 1 child (only left)
        if (root->left && !root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: 1 child (only right)
        if (!root->left && root->right) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: 2 children
        // We have two options:
        //  1) Find inorder successor from root->right, We'd find the min value there
        //  2) Or we can find inorder predecessor from root->left, we'd find the max value there
        else if(root->left && root->right){
            int mini = minVal(root->right); // find inorder successor
            root->data = mini;              // replace data
            root->right = deleteFromBST(root->right, mini); // delete successor node
            // If we didn't call for root->right it will break our logic because mini is repaced by root so it trys to delete itslef.
            return root;
        }
        
    }
    else if(val < root->data) {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main()
{   
    Node* root = NULL;
    cout<< "Enter data in BST: ";
    takeInput(root); //Sample input: 10 8 21 7 27 5 4 3 -1
/*
           10
          /  \
         8    21
        /       \
       7         27
      /
     5
    /
   4
  /
3
*/
    cout <<endl << "Printing Level order: ";
    levelOrderTraversal(root);

    cout <<endl << "Printing inorder: " <<endl;
    inorder(root);
    cout <<endl << "Printing preorder: " <<endl;
    preorder(root);
    cout <<endl << "Printing postorder: " <<endl;
    postorder(root);

    cout << "\nMin value of tree is: " << minVal(root) << "\nMax value of tree is: " << maxVal(root) << endl;

    cout << "Deleted node 5" << endl;
    deleteFromBST(root, 5);

    cout << "Now the tree is: " << endl; 
    levelOrderTraversal(root);
    return 0;
}