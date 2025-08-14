#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //BFS works level by level so when pushing into the q distance will be increased by 1 as it is the next level
        int n = mat.size(), m = mat[0].size();
        //Step1: make a queue and push all 0's with there {{r,c}, 0 dist}
        queue<pair<int, int>> q; // {r,c}
        vector<vector<int>> ans(n, vector<int>(m, -1)); // -1 means unknown dist

         for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(mat[r][c] == 0) {
                    q.push({r, c});
                    ans[r][c] = 0;
                }
            }
        }

        //Step2: process all ele inside queues
        //up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                //find out neighbouring rows and cols
                int nr = r + drow[i]; //new row
                int nc = c + dcol[i];

                // new row, col should be valid and dist must be unknown(-1)
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1) {
                    q.push({nr, nc});
                    ans[nr][nc] = ans[r][c] + 1; // distance from current + 1 
                }
            }
        }
        return ans;
    }
};