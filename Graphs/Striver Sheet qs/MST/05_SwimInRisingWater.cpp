#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// ! https://leetcode.com/problems/swim-in-rising-water/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        //Using Dijkstra's Algo
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>>level(n, vector<int>(n, INT_MAX));

        int dir[] = {-1, 0, 1, 0, -1};

        pq.push({grid[0][0], {0, 0}});
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int currLevel = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if(x == n-1 && y == n-1) return currLevel;

            for(int i = 0; i < 4; i++) {
                int dx = x + dir[i];
                int dy = y + dir[i+1];

                if(dx >= 0 && dx < n && dy >= 0 && dy < n) {

                    int newLevel = max(currLevel, grid[dx][dy]);
                    if(level[dx][dy] > newLevel) {
                        pq.push({newLevel, {dx, dy}});
                        level[dx][dy] = newLevel;
                    }
                }
            }
        }
        return 0;
    }
};