#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Key Steps for This Pattern
/* 
1. Identify the “escape” area → often boundary cells or a certain value.
2. Run DFS/BFS from that area first → mark everything connected as visited.
3. Count / modify the rest → remaining cells are guaranteed to meet the problem condition.
*/

//!  https://leetcode.com/problems/number-of-enclaves/
/*
Intuaiton: Traverse all boundary 1's manually and mark them visited then whichever cells are 1 and not visited they are our ans
*/
class Solution {
public:
    void DFS(int r, int c, vector<vector<bool>> &vis, int dir[], vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0 || vis[r][c])
            return;

        vis[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i], nc = c + dir[i+1];
            DFS(nr, nc, vis, dir, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dir[] = {-1, 0, 1, 0, -1};

        // Step 1: DFS from all boundary land cells
        for (int r = 0; r < n; r++) {
            if (grid[r][0] == 1 && !vis[r][0]) DFS(r, 0, vis, dir, grid);
            if (grid[r][m-1] == 1 && !vis[r][m-1]) DFS(r, m-1, vis, dir, grid);
        }
        for (int c = 0; c < m; c++) {
            if (grid[0][c] == 1 && !vis[0][c]) DFS(0, c, vis, dir, grid);
            if (grid[n-1][c] == 1 && !vis[n-1][c]) DFS(n-1, c, vis, dir, grid);
        }

        // Step 2: Count remaining unvisited land cells
        int ans = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == 1 && !vis[r][c])
                    ans++;
            }
        }
        return ans;
    }
};
