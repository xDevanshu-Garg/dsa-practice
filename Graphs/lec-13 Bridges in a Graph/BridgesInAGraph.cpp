//Also known as Tarjan's algo
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
 vector<bool> &vis, vector<vector<int>> &bridges, vector<vector<int>> &adj) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for(auto& nei: adj[node]) {
        //Skip if nei is equals to parent
        if(nei == parent) continue;

        if(!vis[nei]) {
            DFS(nei, node, timer, disc, low, vis, bridges, adj);

            //While returning update low of node
            low[node] = min(low[node], low[nei]);

            //check for bridge or not
            // we're saying if low of nei is greater then discovery time of node it means nei is directly dependent on node other wise if low[nei] is less then discovery time of node it means nei has another path to reach node let's say low[nei] = 6 and disc[node] = 8 so nei will take step 7 and then step 8 to reach node simple.
            // in simple words nei is saying agr mera low tere se chota h to meri pauch bht uper tk h m tere baap dada ko janta hu to tere hat jane se m alag component nhi ban jayunga kyuki tere baap dada se rista(edge) h hamara unhone pakad rakha h mujhe. pr agr nei ka low bada niklta h node ke discovery time se to nei poora poora dependent h node pr to node aur nei ka connection toot jaye to nei isolate ho jayega
            if(low[nei] > disc[node]) {
                bridges.push_back({node, nei});
            }
        }
        else{ // nei is visited means back edge case means nei is also a parent of node
            //Update low to discovery time of it's nei
            low[node] = min(low[node], disc[nei]);
        }
    }

}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //Make adj list
    vector<vector<int>> adj(v);
    for(auto& edge: edges) {
        adj[edge[0]].push_back(edge[1]);        
        adj[edge[1]].push_back(edge[0]);
    }

    //Create and initialize DS
    int timer = 0;
    int parent = -1;  
    vector<int> disc(v, -1); //It stores in which step DFS reached a node
    vector<int> low(v, -1);  //graph have multi brances so low stores minimum time to reach that node aprat from DFS time
    vector<bool> vis(v, false);
    vector<vector<int>> bridges;

    //DFS
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            DFS(i, parent, timer, disc, low, vis, bridges, adj);
        }
    }

    return bridges;
}