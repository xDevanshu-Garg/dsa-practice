// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &mat, vector<vector<int>> &visited, string output, vector<string> &results, int index1, int index2)
{
    // BC
    if (index1 == mat.size() - 1 && index2 == mat.size() - 1)
    {
        results.push_back(output);
        return;
    }
    if (index1 < 0 || index2 < 0 || index1 >= mat.size() || index2 >= mat.size())
        return;
    if (mat[index1][index2] == 0 || visited[index1][index2] == 1)
        return;

    visited[index1][index2] = 1;

    // RR
    // Right
    output.push_back('R');
    solve(mat, visited, output, results, index1, index2 + 1);
    output.pop_back();
    // Down
    output.push_back('D');
    solve(mat, visited, output, results, index1 + 1, index2);
    output.pop_back();
    // up
    output.push_back('U');
    solve(mat, visited, output, results, index1 - 1, index2);
    output.pop_back();
    // Left
    output.push_back('L');
    solve(mat, visited, output, results, index1, index2 - 1);
    output.pop_back();

    // Mark as non visited again
    visited[index1][index2] = 0;
}
vector<string> findPath(vector<vector<int>> &mat)
{
    vector<vector<int>> visited(mat.size(), vector<int>(mat.size(), 0));
    string output;
    vector<string> results;
    if (mat[0][0] == 0)
        return {}; // No path possible
    solve(mat, visited, output, results, 0, 0);
    return results;
}

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = findPath(mat);
    for(auto s: ans){
        cout << s <<endl;
    }
    return 0;
}