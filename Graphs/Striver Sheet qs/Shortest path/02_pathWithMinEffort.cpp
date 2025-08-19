#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>>effort(n, vector<int>(m, INT_MAX));
        int dir[] = {-1, 0, 1, 0, -1};
        pq.push({0, {0, 0}}); //Intital push {effort, {x, y}}


        while(!pq.empty()) {
            auto front = pq.top(); pq.pop();
            int currEffort = front.first;
            int x = front.second.first;
            int y = front.second.second;

            //Check wheter this is n-1, n-1 or not
            if(x == n-1 && y == m-1) return currEffort;

            for(int i = 0; i < 4; i++) {
                int dx = x + dir[i];
                int dy = y + dir[i+1];

                if(dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    int newEffort = max(currEffort, abs(heights[x][y] - heights[dx][dy]));
                    if(newEffort < effort[dx][dy]) {
                        pq.push({{newEffort}, {dx, dy}});
                        effort[dx][dy] = newEffort;
                    }
                }
            }
        }

        return 0;
    }
};
/*
TC: We know dijkstra's TC is O(E*V * log(V))
here E is 4 because a node have 4 directions or 4 edges
V is n * m or a capital N
so TC is O(4N * log(N)) or O(N * log(N)) or O(E*V * log(E*V))
SC: O(N) or O(n*m)
*/