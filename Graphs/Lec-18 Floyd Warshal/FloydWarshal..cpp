#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This is a multisouce shortest path, it also helps to detect negative cycles as well
//! https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// We can use Dijkstra if there are no negative cycles otherwise Dijkstra's algo fails. If there are no neg cycles then Dijkstra's TC will be O(v * e log v), while FW's TC is O(v^3)
// Dijkstra works on regular cycles well, but not in negative cycles, FW detects this, let's say we are starting from 0 and reaching 0 in -3 time, that's impossible. 
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

// TC: O(n^3), SC = O(n^2) (space of matrix itself used for calculation)

/*
! Negative Cycle Case: Diagonal will be less then 0
for(int i = 0; i < n; i++) {
    if(dist[i][i] < 0) cout << "Negative cycle"; 
}
    
*/
// Learn how dij tc works