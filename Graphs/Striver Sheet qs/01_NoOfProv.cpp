#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //Adjacency matrix is given let's convert it to adj list
        
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && i != j) {
                    adj[i+1].push_back(j+1);
                }
            }
        }

        unordered_map<int, bool> visited;
        int count = 0;
        for(int start = 1; start <= n; start++) {
            if(!visited[start]) {
                count++;
                queue<int> q;
                q.push(start);
                visited[start] = true;

                while(!q.empty()) {
                    int frontNode = q.front();
                    q.pop();

                    for(auto neighbour: adj[frontNode]) {
                        if(!visited[neighbour]) {
                            q.push(neighbour);
                            visited[neighbour] = true;
                        }
                    }
                }
            }
        }
        return count;
    }
};

//adj list can be 0 based example are showing starting node as 1 so I started from 1 but it can start from 0 too 