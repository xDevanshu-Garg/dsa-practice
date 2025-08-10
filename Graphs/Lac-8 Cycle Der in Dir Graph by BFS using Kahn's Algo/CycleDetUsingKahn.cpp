#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
  //Using kahn's algo

  //Making adj list and finding indegree
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for(auto edge: edges) {
      //-1 to make 1 based input to 0 based
        adj[edge.first - 1].push_back(edge.second - 1);
        //find out indegree of node
        indegree[edge.second - 1]++;
    }

    // Push 0 degree nodes into the queue
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    // Do normal BFS and when removing a node from the queue remeber that now it's neighbour's indegree will be one less
    int count = 0;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        count++;

        for(int nei: adj[frontNode]) {
            // Neighbour's degree will be decremented by 1 cuz it's parent has been removed
            indegree[nei]--;
            if(indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    if(count == n) //This means that kahn's algo was successful this means there is no cycle because kahn's algo works on direc acyclic graph only
      return false;
    
    return true;
}