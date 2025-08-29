#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/making-a-large-island/

//Idea: Use DSU to map out which node belongs to which component so that it's efficient to find size when we'll flip 0's
//Map rows and cols using n*r + c formula where n is no. of cols
class DSU {
    public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1); // Initial size is 1

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        //Step1: Apply DSU
        // 1 2 4 belongs to 1 and size is 3
        // 6 8 9 belongs to 6 and size is 3

        //Step2: Traverse grid and if there is 0 try to change it to 1 and then find parents in all 4 dirn if parent is diff then add it's size into max area. Then do the same for another 0 and so on. 

        // area = unique parent nodes size + 1

        //Step1: Apply DSU
        int n = grid.size();
        DSU dsu(n * n); // n*n sized 
        int dir[] = {-1, 0, 1, 0, -1};

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1) {

                    for(int i = 0; i < 4; i++) {
                        int nr = r + dir[i];
                        int nc = c + dir[i+1];

                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int u = n*r + c;
                            int v = n*nr + nc;
                            dsu.unionBySize(u, v);
                        }
                    }
                }
            }
        }

        //Step2:

        int maxArea = 0;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) { 

                if(grid[r][c] == 0) {
                    unordered_set<int> uniqeParents;
                    int area = 1; //1 because 0 itself will add 1 size

                    for(int i = 0; i < 4; i++) {
                        int nr = r + dir[i];
                        int nc = c + dir[i+1];
                        int u = n*nr + nc;

                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 && 
                        uniqeParents.find(u) == uniqeParents.end()) {
                            uniqeParents.insert(dsu.findParent(u));

                        }
                    } 
                    for (int ele : uniqeParents) {
                        area += dsu.size[ele];
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }

        // Corner case: if grid is already all 1's
        if(maxArea == 0) {
            for(int i = 0; i < n*n; i++) {
                if(dsu.findParent(i) == i)
                    maxArea = max(maxArea, dsu.size[i]);
            }
        }

        return maxArea;
    }
};