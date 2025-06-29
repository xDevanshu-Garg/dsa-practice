#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // To store final ans and return
        vector<vector<int>> ans;
        //Base case check
        if(!root) return ans;
        //Queue for level order traversal( Node, {Horizontal Distance, level})
        queue<pair<TreeNode*, pair<int, int> > > q;
        //map to map out HD->{lvl->{node's value}}
        map<int , map<int , multiset<int> > > mapping;

        //Initialize queue with first value
        q.push({root, {0,0}});
        
        //Did rest of level order traversal
        while(!q.empty()){
            auto temp = q.front();

            TreeNode* frontNode = temp.first;
            int HD = temp.second.first;
            int lvl = temp.second.second;

            q.pop();
            //Store this data to use in final ans
            mapping[HD][lvl].insert(frontNode->val);

            if(frontNode->left) q.push({frontNode->left, {HD-1, lvl+1}});
            if(frontNode->right) q.push({frontNode->right, {HD+1, lvl+1}});
        }

        // Extract our final ans
        for(auto i: mapping){
            vector<int> col;
            for(auto j: i.second){
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};