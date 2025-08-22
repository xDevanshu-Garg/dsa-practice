#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        //Using kahn's algo

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), ans;

        for(auto it: prerequisites) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        // push all 0 indegrees into q
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        //Traverse using BFS
        int nodeCount = 0;
        while(!q.empty()) {
            int node = q.front(); 
            q.pop();
            ans.push_back(node);
            nodeCount++;

            for(int nei: adj[node]) {
                indegree[nei]--;
                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if(nodeCount == n){
            reverse(ans.begin(), ans.end());
            return ans;
        }
        else return {};
    }
};