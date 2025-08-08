//! https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTabValue=PROBLEM
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

When BFS moves from u to v, you’ll immediately see an edge back from v to u. That’s not a cycle — it’s just the same edge in the opposite direction. so u is the parent of v so we'll have no problem when from v u comes we can say oh 'u' you're already visited then you must be my parent right? If yes then no probelm but if No then 'u' must've visited by another branch so our conditon for cycle detection is that if let's say node v has neighbour u and it is already visited and u is not the parent of v then there is a cycle.


1. BFS builds a tree structure as it explores
When BFS first visits a node v from u, it records u as parent[v].

That means the edge u ↔ v is part of the BFS tree, not a cycle.

2. Why we check if (visited[neighbour] && neighbour != parent[current])
When BFS processes current (say v) and sees a neighbor neighbour (say u):

If u is the parent of v, that’s just the edge we came from — ignore it.

If u is visited but not the parent, it means:

We reached u through another route, not through v.

That “other route” + the current edge (v, u) forms a loop → cycle.

3. Intuition as a conversation
Imagine BFS nodes talking:

v: “Hey u, I see you’re visited. Are you my parent?”
u: “Nope, I was visited by some other guy earlier.”
v: “Ah, so there’s another path to you? That means we’ve closed a loop!” ✅

Visual Trigger in Your Head
Picture BFS like spreading roots of a tree.


//* Visual
If two roots meet underground (visited node from another branch) → you’ve dug into the same spot twice → cycle!

   1
  / \
 2   3
  \ /
   4   ← meeting point, cycle
 
*/

#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //Creating adj list
    vector<vector<int>> adj(n + 1);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    
    for(int start = 1; start <= n; start++) {
        
        if(!visited[start]){
            q.push(start);
            visited[start] = true;
            parent[start] = -1;
            
            while(!q.empty()) {
                int frontNode = q.front();
                q.pop();
                
                for(int neighbour: adj[frontNode]) {
                    if(visited[neighbour] && neighbour != parent[frontNode]) {
                        return "Yes";
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
    return "No";
}
