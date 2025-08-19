#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//TC = SC = O(N * M)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int> , int>> q; // {{r,c} , time}
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Mark all the initial rotten oranges as visited and push into q
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int time = 0;
        //up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        //Do BFS while cheking in all 4 direc
        while(!q.empty()) {
            auto front = q.front();
            int r = front.first.first;
            int c = front.first.second;
            int t = front.second;
            time = max(time, t);
            q.pop();

            for(int i = 0; i < 4; i++) {
                //find out neighbouring rows and cols
                int nrow = r + drow[i]; 
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                 && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        //Before returning the time check all the fresh oranges are now rotten or not
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return time;
    }
};