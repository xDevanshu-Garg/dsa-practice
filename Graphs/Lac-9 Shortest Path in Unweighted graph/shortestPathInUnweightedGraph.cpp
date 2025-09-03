#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Logic: We'll use BFS. 
why? Because BFS explore all nodes level by level so naturally when started from src then it will reach dest the path it took surely is shortest because we're going level by level. I've attached image see that
*/

//TC is one pass every node means O(N + E)
// SC is O(n) for parent, vis, ans(at max) and O(N + E) for adj list so total 
// TC + SC = O(N + E);
vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	//Making adj list
	vector<vector<int>> adj(n + 1);
	for(auto &edge: edges) {
		adj[edge.first].push_back(edge.second);		
		adj[edge.second].push_back(edge.first);
	}

	//For shortest path we'll need parent array to backtrack to src
	vector<int> parent(n+1);
	vector<int> vis(n+1);
	queue<int> q;

	parent[s] = -1;
	vis[s] = true;
	q.push(s);

	while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == t) break; // early exit

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

	vector<int> ans;
	int node = t;
	while(node != -1) {
		ans.push_back(node);
		node = parent[node];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}



/***************shortest way (count) *****************/
//return count 
//It uses a distance vector, it also merges visited in distance vector dist[node] = -1 means not visited and = 0 means distance of that node to itself is 0
// When we move forward one lvl just increase the dist of that node with +1 dist of it's parent 

int shortestPath(int n, vector<vector<int>> &edges, int src, int dest) {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]); // undirected
    }

    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) { // unvisited
                dist[v] = dist[u] + 1;
                q.push(v);
                if (v == dest) return dist[v]; // early stop
            }
        }
    }
    return -1; // no path
}

//3rd way of writing using queue<pair<int, int>> to store node and dist
int shortestPath(int n, vector<vector<int>> &edges, int src, int dest) {

    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]); // undirected
    }

    vector<bool> vis(n, false);
    queue<pair<int,int>> q; // {node, distance}
    vis[src] = true;
    q.push({src, 0});
    
    while(!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        if(u == dest) return d;
        for(int v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push({v, d+1});
            }
        }
    }
    return -1;
}
