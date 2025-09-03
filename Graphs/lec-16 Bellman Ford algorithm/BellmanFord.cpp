#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Used to calculate shortest dist with negative weight and to check if there is negative cycle or not. 
//Works on Directed Graph only. If UDG comes convert it to DG

/*
Steps: Iterate over n-1 times. 
update dist array when dist[node] + wt < dist[nei]
*/

//! https://www.google.com/search?q=bellman+ford+algorithm+gfg+practice&ie=UTF-8
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i = 0; i < V-1; i++) {
            for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        //We've got our shortest dist vector as ans but quest says to check if there exists a neg cycle or not
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1}; //neg weight cycle exists!!
            }
        }
        
        return dist;
    }
};

//TC = O(VE) SC = O(V)
//Why n-1 iterations? Because edges can be in any order let's say our src is at last in edges then in 1st iteration src updates it's nei node then let's say it's nei node is 2nd last in edges then in 2nd iteration it updates it's nei and so on so in worst case if edges is arranged in such a way that all edge in edges are updating at a time then it'll take n-1 iterations cuz src is already set to 0.