#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/surrounded-regions/description/

class Solution {
    void DFS(int r, int c, int dir[], vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        board[r][c] = 'S';

        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i];
            int nc = c + dir[i+1];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O') 
                DFS(nr, nc , dir, board);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        //We'll use DFS here, reasons are that we don't need to traverse level by level and DFS will save memory too because we'll not need visited array
        int n = board.size(), m = board[0].size();
        int dir[] = {-1, 0, 1, 0, -1};
        // Step 1: Find the border 'O's and perform DFS and mark all regions as 'S' safe in board itself
        
        //For first and last row
        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O'){
                DFS(0, i , dir, board);
            }
            if(board[n-1][i] == 'O'){
                DFS(n-1, i , dir, board);
            }
        }

        //For first and last col
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O'){
                DFS(i, 0 , dir, board);
            }
            if(board[i][m-1] == 'O'){
                DFS(i, m-1 , dir, board);
            }
        }

        // Step 2: O → X, S → O 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};