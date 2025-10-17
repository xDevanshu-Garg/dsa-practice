//! ✏️ Rat in a Maze – All Possible Paths
//!   Problem: https://www.naukri.com/code360/problems/rat-in-a-maze_1215030

/* 
   🎯 Goal:
   Find all paths from (0,0) to (n-1,n-1) in an n x n matrix `arr` where:
     - 1 → open cell
     - 0 → blocked cell
   Movement allowed: Down (D), Left (L), Right (R), Up (U)

   ✅ Backtracking Approach:
   - Explore all 4 directions recursively
   - Use `visited[][]` matrix to avoid revisiting same cell
   - Use string `temp` to track current path
   - On reaching destination (n-1, n-1), add path to result

   🔁 Direction Vectors:
   - dx = {+1,  0,  0, -1}
   - dy = { 0, -1, +1,  0}
   - dir = "DLRU"

   📌 Steps:
   1. If start or destination is blocked → return empty result
   2. Mark current cell visited
   3. Try all 4 directions using dx/dy + dir
   4. Backtrack after recursion → unmark visited & remove char from temp

   🕒 Time Complexity: O(4^(n*n)) in worst case (all cells open)
   💾 Space Complexity:
     - visited[][] → O(n^2)
     - temp path → O(n^2)
     - recursion stack → O(n^2)

   ⚠️ Edge Case:
   - If arr[0][0] == 0 or arr[n-1][n-1] == 0 → no path possible

   ✨ Variations:
   - Count total paths
   - Return only shortest path (use BFS)
   - Return path as coordinates
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(const vector<vector<int>> &arr, int n, vector<vector<int>> &visited, vector<string> &ans, string &temp, int i, int j, const vector<int> &dx, const vector<int> &dy, const string &dir){
    //Base Case
    if(i == n-1 && j == n-1){
        ans.push_back(temp);
        return;
    }

    // Direction loop
    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
            !visited[new_i][new_j] && arr[new_i][new_j] == 1) {

            visited[new_i][new_j] = 1;
            temp.push_back(dir[k]);

            solve(arr, n, visited, ans, temp, new_i, new_j, dx, dy, dir);

            temp.pop_back(); // Backtrack
            visited[new_i][new_j] = 0;
        }
    }
}

vector < string > searcharr(vector<vector<int>> &arr, int n) {

    vector<string> ans;

    if (arr[0][0] == 0 || arr[n - 1][n - 1] == 0)
        return ans;  // No path possible

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string temp = "";    
    visited[0][0] = 1;

    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    string dir = "DLRU";

    solve(arr, n, visited, ans, temp, 0, 0, dx, dy, dir);
    return ans;
}