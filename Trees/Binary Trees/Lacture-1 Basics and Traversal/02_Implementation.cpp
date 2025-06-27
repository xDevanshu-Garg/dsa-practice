#include <iostream>
#include <queue> 
#include <stack> 
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Function to build a binary tree recursively using pre-order input
// Input Format: Enter value, -1 indicates no node
Node* buildTree() {
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1) return nullptr;

    Node* root = new Node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree();

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree();

    return root;
}

// Function to perform level-order (breadth-first) traversal of the tree
// Each level is printed on a new line
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

void reverseLevelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    stack<Node*> s;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Push the current node to stack
        s.push(temp);

        // ⚠️ Push right first so that left comes out first when reversed
        if (temp->right) q.push(temp->right);
        if (temp->left) q.push(temp->left);
    }
        

    // Now pop all nodes from stack and print
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

void buildFromLevelOrder(Node* &root){

    queue<Node*> q;
    cout<<"Enter data for root: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for " <<temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for " <<temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
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

int main() {
    /*
    Node* root = buildTree();  
    // Example input: 3 4 6 -1 -1 7 -1 -1 5 8 -1 -1 9 -1 -1

    // Print the level order traversal
    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\nReverse Level Order Traversal:\n";
    reverseLevelOrderTraversal(root);

    cout << "\n In Order Traversal:\n";
    inorder(root);

    cout << "\n Pre Order Traversal:\n";
    preorder(root);

    cout << "\n Post Order Traversal:\n";
    postorder(root);

    */

    Node* root = NULL;
    buildFromLevelOrder(root);

    // Input data example: 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    return 0;
}