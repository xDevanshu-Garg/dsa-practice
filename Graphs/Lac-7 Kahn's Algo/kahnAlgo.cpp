#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Used to do TOPO sort using BFS

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //Making adj list
    vector<vector<int>> adj(v);
    vector<int> indegree(v, 0);
    for(auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        //find out indegree of node
        indegree[edge[1]]++;
    }
    //if we want to find out indegree from adj list we would travarse adj list and will increment the nodes cuz indgree of a node = how many times that node has appeared in adj list indegree[node]++; node will come from 2 for loops like elements in a matrix

    // Push 0 degree nodes into the queue
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    // Do normal BFS and when removing a node from the queue remeber that now it's neighbour's indegree will be one less
    vector<int> ans;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(int nei: adj[frontNode]) {
            // Neighbour's degree will be decremented by 1 cuz it's parent has been removed
            indegree[nei]--;
            if(indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }
    return ans;
}
//TC = SC = O(N + E)