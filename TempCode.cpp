#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, bool> visited;
        
        for(int start = 0; start < V; start++) {
            if(!visited[start]) {
                queue<int> q;
                unordered_map<int, int> parent;

                q.push(start);
                visited[start] = true;
                parent[start] = -1;

                while(!q.empty()) {
                    int frontNode = q.front();
                    q.pop();

                    for(int neighbour: edges[frontNode]) {
                        if(visited[neighbour] && neighbour != parent[frontNode]) {
                            return true;
                        }
                        if(!visited[neighbour]) {
                            q.push(neighbour);
                            visited[neighbour] = true;
                            parent[neighbour] = frontNode;
                        }
                    }
                }
            }
        }
        return false;
    }
};
