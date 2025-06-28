#include<iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


void inorder(BinaryTreeNode<int>* root, int &count){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL) count++;
    inorder(root->left, count);
    inorder(root->right, count);
}

void levelOrderTraversal(BinaryTreeNode<int>* root, int &count) {
    if (!root) return;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        BinaryTreeNode<int>* temp = q.front();
        q.pop();

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        if(temp->left == NULL && temp->right == NULL) count++;

    }
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0;
    // inorder(root, count);
    levelOrderTraversal(root, count);
    return count;
}

int main() {
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    cout << "Number of leaf nodes: " << noOfLeafNodes(root) << endl;
    return 0;
}
