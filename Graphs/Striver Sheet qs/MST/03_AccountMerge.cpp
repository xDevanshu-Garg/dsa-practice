#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void makeSet(vector<int> &parent, vector<int> &rank) {
        int n = parent.size();
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // find the parent's root and update parent[node] directly (path compression)
    // Stop when you're your own parent
    int findParent(vector<int> &parent, int node) {
        if (node == parent[node])
            return node;

        // assign the new parent for node
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        //if rank of node is greator make it parent so we can find parent in lesser time
        if (rank[u] < rank[v])
            parent[u] = v;
        
        else if (rank[u] > rank[v])
            parent[v] = u;

        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n);
        makeSet(parent, rank);

        //Step1: Map out mails with nodes
        unordered_map<string, int> mapMailNode;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) { //start from 1 to skip name
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    unionSet(i, mapMailNode[mail], parent, rank);
                }
            }
        }

        //Step2: Combine or store the emails with their ultimate parent
        vector<vector<string>> mergedMail(n);
        for(auto& it: mapMailNode) {
            string mail = it.first;
            int node = findParent(parent, it.second);

            mergedMail[node].push_back(mail);
        }

        //Step3: sort them except empty onces and store them in ans
        //Ans is 
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]); //Push the name
            for(auto& it: mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};