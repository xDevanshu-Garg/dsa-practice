#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void levelOrderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout<<endl;
            //above we encounter temp = NULL which means we've travered a level already so checking q is not empty means jo level traverse ho chuka h kya usme childs the agr the to unke baad null laga do
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->val <<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

//! https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
/*
what we're doing is that inorder traversal of LL
so we first find out length of LL
then we need to buildtree on left till n/2
then we make our root node from curr head and move the curr head forward which will now point to n/2 + 1 and connect root->left to left subtree and root->right will we subtree right from head to n - n/2 - 1 cuz that's all left.
*/
class Solution{
public:
    int countNodes(ListNode *&head){
        int count = 0;
        ListNode *temp = head;
        while (temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

    TreeNode *buildTree(ListNode *&head, int n){
        if (n == 0)
            return NULL;

        TreeNode *left = buildTree(head, n / 2);

        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = buildTree(head, n - n / 2 - 1);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head){
        if (!head)
            return NULL;
        return buildTree(head, countNodes(head));
    }
};
int main(){
    Solution s;

    // Properly creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    TreeNode* newHead = s.sortedListToBST(head);
    levelOrderTraversal(newHead);
    
    return 0;
}
