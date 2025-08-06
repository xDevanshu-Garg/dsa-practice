#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*

E = number of empty cells
Each cell can have up to 9 possibilities.

Checking a possibility is O(1) due to the rowMap, colMap, boxMap arrays.

So, worst case:

T(E) ≈ O(9^E)

But because of pruning (invalid placements are discarded immediately), average complexity is much smaller.
 
SC is constant recursion dept is maxm O(81) or O(E) vectors are also constant sizes
 */

class Solution {
public:

bool solve(vector<vector<char>>& board, vector<array<bool,10>> &rowMap, vector<array<bool,10>> &colMap, vector<array<bool,10>> &boxMap) {
    int N = board.size();
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == '.'){
                int box = (r / 3) * 3 + (c / 3);
                for(int i = 1; i <= 9; i++){
                    if(!rowMap[r][i] && !colMap[c][i] && !boxMap[box][i]){

                        // place
                        board[r][c] = char('0' + i);
                        rowMap[r][i] = colMap[c][i] = boxMap[box][i] = true;

                        bool isSolPossible = solve(board, rowMap, colMap, boxMap);
                        if(isSolPossible){
                            return true;
                        }

                        //Backtrack
                        else{
                            //In later calls Solution not possible so backtrack curr step
                            board[r][c] = '.';
                            rowMap[r][i] = colMap[c][i] = boxMap[box][i] =  false;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        // filling vectors
        int n = board.size();
        vector<array<bool,10>> rowMap(9), colMap(9), boxMap(9);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] != '.') {
                    int ele = board[r][c] - '0';     // 1..9
                    int box = (r / 3) * 3 + (c / 3); // 0 1 2   3 4 5   6 7 8

                    rowMap[r][ele] = true;
                    colMap[c][ele] = true;
                    boxMap[box][ele] = true;
                }
            }
        }
        solve(board, rowMap, colMap, boxMap);
    }
};