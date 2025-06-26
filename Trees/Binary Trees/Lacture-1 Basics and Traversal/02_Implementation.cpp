#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node* root){
    cout << "Enter data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) return nullptr;

    cout << "Enter data for inserting in left of " <<data << endl;
    buildTree(root->left);

    cout << "Enter data for inserting in right of " <<data << endl;
    buildTree(root->right);

    return root;
}

int main()
{
    Node* root;
    root = buildTree(root);
    return 0;
}