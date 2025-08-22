#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path) {
        vis[node] = path[node] = 1;

        for (auto nei : adj[node]) {
            if (!vis[nei]) {
              dfs(nei, adj, vis, path); 
            }
            
            if (vis[nei] && path[nei])
                return;
        }
        path[node] = 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        /*
        Observation: Any node that is in the cycle or connected to cycle are not safe nodes
        Idea: We'll Use DFS to check if there is a cycle in Dir Graph
           -> Everything is same as cycle in dir graph algo
           -> But once we'll get a cycle we'll not reset pathVisited so we'll know whichever node is still in pathVisited are unsafe nodes
           or we can just use normal algo with bool return type except we keep another vector safe at end when we conferm oh you've got no nei so let's break out of for loop and unmark pathVisited at that time you can say it's safe too so at last traverse for safe array

        */

        int n = graph.size();

        vector<int> vis(n, 0), path(n, 0), safe;

        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(i, graph, vis, path);

        for(int i = 0; i < n; i++) {
            if(!path[i]) {
                safe.push_back(i);
            } 
        }
        return safe;
    }
};


// ******************************Reversed graph + Kahn's Aglo************************************

/*
We obsereved that terminal nodes were safe or outdegree 0 nodes were safe and then we we're doing kahn's algo it's working because if we remove terminal node then it's nei outdegree also decreases if it's nei's outdegree is 0 means it's also a safe node so what we did is reverse the graph and outdegree became indegrees and then we perform normal kahn's algo
*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        //Reverse the adj list
        vector<vector<int>> adjRev(n);
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(auto it: graph[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        //Now do normal topo sort and store safe nodes
        vector<int> safeNodes;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
    
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(int nei: adjRev[node]) {
                indegree[nei]--;
                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};