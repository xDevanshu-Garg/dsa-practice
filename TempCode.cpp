#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     bool solve(int node, vector<vector<int>> &adj, vector<int> &color, int v, int m) {
//         //Base Case: When nodes are over
//         if(node > v) return true;
        
//         for(int i = 0; i < m; i++) {
            
//             bool isSafe = false;
//             for(auto nei: adj[node]) {
//                 if(color[nei] == i) {
//                     isSafe = false;
//                 }
//             }
//             if(isSafe) {
//                 color[node] = i;
//                 if(solve(node+1, adj, color, v, m)) return true;
//             }
            
//         }
//         return false;
//     }
    
//     bool graphColoring(int v, vector<vector<int>> &edges, int m) {
//         //Making an adj list
//         vector<vector<int>> adj(v);
//         for(auto& edge: edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
        
//         vector<int> color(m, -1);
//         return solve(0, adj, color, v, m);
    // }
// };

int main() {
    // Write C++ code here
    string s = "123";
    string currStr = s.substr(0, 0 - 0 + 1);
    std::cout << currStr;

    return 0;
}