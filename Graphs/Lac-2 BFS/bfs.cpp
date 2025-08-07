#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://www.naukri.com/code360/problems/bfs-in-graph_973002?leftPanelTabValue=SUBMISSION
//Commented out for loop is when we've given disconnected graph so there is no edges to some vertices means there's no way we can reach there. That's why we'll use a for loop to explicitly enter some vertices. 
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    queue<int> q;
    unordered_map<int, bool> visited;

    // for(int i = 0; i < n; i++){
    //     if(!visited[i]){
            q.push(0);
            visited[0] = true;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                ans.push_back(frontNode);
                

                //Traverse all vertices related to frontNode
                for(int ele: adj[frontNode]){
                    if(!visited[ele]){
                        q.push(ele);
                        visited[ele] = true;
                    }
                }
            }
    //     }
    // }
    return ans;
}