#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &arr, int n, vector<vector<int>> &visited, vector<string> &ans, string &temp, int i, int j) {
    // Check bounds and validity
    if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] == 1 || arr[i][j] == 0) {
        return;
    }

    // Base Case
    if(i == n-1 && j == n-1){
        ans.push_back(temp);
        return;
    }

    visited[i][j] = 1;

    // D
    temp += "D";
    solve(arr, n, visited, ans, temp, i+1, j);
    temp.pop_back();

    // L
    temp += "L";
    solve(arr, n, visited, ans, temp, i, j-1);
    temp.pop_back();

    // R    
    temp += "R";
    solve(arr, n, visited, ans, temp, i, j+1);
    temp.pop_back();

    // U
    temp += "U";
    solve(arr, n, visited, ans, temp, i-1, j);
    temp.pop_back();

    visited[i][j] = 0; // backtrack
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    if(arr[0][0] == 0 || arr[n-1][n-1] == 0) return ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string temp = "";
    solve(arr, n, visited, ans, temp, 0, 0);
    return ans;
}
