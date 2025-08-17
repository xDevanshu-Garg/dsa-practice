#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Approach (DFS):
- Maintain a color array (-1 = uncolored, 0/1 = two colors).
- For each unvisited node, run DFS and assign a starting color.
- In DFS: assign current color, then try coloring neighbors with opposite color.
- If a neighbor already has the same color → not bipartite.
- Repeat for all components (graph may be disconnected).
- Time: O(V + E), Space: O(V).
*/

class Solution {
public:
    bool DFS(int node, vector<int> &color, int col, vector<vector<int>>& graph) {
        color[node] = col;
        
        for(auto nei: graph[node]) {
            if(color[nei] != -1) {
                if(color[nei] == color[node]) return false;
            }
            else{
                bool isBp = DFS(nei, color, !col, graph);
                if(!isBp) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1){
                bool ans = DFS(i, color, 0, graph);
                if(ans == false) return false;
            }
        }
        return true;
    }
};