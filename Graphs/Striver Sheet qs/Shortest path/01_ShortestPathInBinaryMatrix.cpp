#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       //We'll use BFS as it is unweighted graph
       int n = grid.size();
       //Edge case
       if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
       if (n == 1) return grid[0][0] == 0 ? 1 : -1; // Or just simply 1 because we checked it earlier

        // Make a dist vector which will be used to track visited if dist[v] = -1 and also dist of vertex v
        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][0] = 1;

        //up, up-right, right, right-down, down, down-left, left, left-up
        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        queue<pair<int, int>> q;
        q.push({0, 0});

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 8; i++) {
                //find out neighbouring rows and cols
                int nrow = r + drow[i]; 
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n
                 && dist[nrow][ncol] == -1 && grid[nrow][ncol] == 0) {
                    q.push({nrow, ncol});
                    dist[nrow][ncol] = dist[r][c] + 1;
                    if(nrow == n-1 && ncol == n-1) return dist[nrow][ncol]; //return early
                }
            }
        }
        return -1;
    }
};