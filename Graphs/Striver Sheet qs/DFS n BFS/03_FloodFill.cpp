#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leet2code.com/problems/flood-fill/description/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int scolor = image[sr][sc];

        queue<pair<int, int>> q; // {r,c}
        q.push({sr, sc});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                 && image[nrow][ncol] == scolor && !vis[nrow][ncol]) {
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return image;
    }
};