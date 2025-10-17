#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// ************Without optimization**********************

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        // Check for row(only left side), diagonals(left up and left down)
        // Our recursion is in such a way that it doesn't allow duplicate queens in same col so no need to check cols

        //For row (left side only)
        int x = row, y = col;
        while(y >= 0){
            if(board[x][y--] == 'Q') return false;
        }

        //For left upper diagonal
        x = row, y = col;
        while(x >= 0 && y >= 0){
            if(board[x--][y--] == 'Q') return false;
        }

        // For left lower diagonal
        x = row, y = col;
        while(x < n && y >= 0){
            if(board[x++][y--] == 'Q') return false;
        }

        return true;
    }

    void solve(int colNo, vector<string>& board, vector<vector<string>>& ans, int n){
        //Base Case: You have placed all your n queens
        if(colNo == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, colNo, board, n)){
                board[row][colNo] = 'Q';
                solve(colNo+1, board, ans, n);
                board[row][colNo] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, board, ans, n);
        return ans;
    }
};


// ********************With optimization*****************************
class Solution {
public:
    void solve(int colNo, vector<string>& board, vector<vector<string>>& ans, int n, vector<bool>& leftRow, vector<bool>& upperDiagonal, vector<bool>& lowerDiagonal) {
        // Base Case: You have placed all your n queens
        if (colNo == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            int lower = row + colNo, upper = n - 1 + colNo - row;

            if (!leftRow[row] && !lowerDiagonal[lower] && !upperDiagonal[upper]) {

                // Place Queen
                board[row][colNo] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[lower] = 1;
                upperDiagonal[upper] = 1;

                solve(colNo + 1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

                // Backtrack
                board[row][colNo] = '.';
                leftRow[row] = 0;
                lowerDiagonal[lower] = 0;
                upperDiagonal[upper] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        // To optimize isSafe using hashing
        // for 4 sized board diagonals can be 0 1 2 3 4 5 6 so there are 7 elements means 2*4 -1 elements that's why size is 2*n-1
        vector<bool> leftRow(n, 0);
        vector<bool> upperDiagonal(2*n - 1, 0); 
        vector<bool> lowerDiagonal(2 * n - 1, 0);
        vector<vector<string>> ans;

        solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};