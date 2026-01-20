#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! https://leetcode.com/problems/largest-magic-square/
//? In this ques I learned about how to optimized using row, col, dia1(\), dia2(/) prefixes

/* BRUTE FORCE
for each i
  for each j
    for each k
      check if k×k square starting at (i,j) is magic

    O(N³ + 2k² + k) N³ for three loops and k² for isMagic
*/

// *********************************************BRUTE FORCE*************************************************
// See how for loops conditions are written
class Solution {
    public:
    bool isMagic(int r, int c, int k, vector<vector<int>>& grid) {
        int target = 0;
        // For first row, so we can find target
        for(int j = c; j < c + k; j++) 
        target += grid[r][j];
        
        // Check all rows
        for(int i = r; i < r + k; i++) {
            int sum = 0;
            for(int j = c; j < c + k; j++) {
                sum += grid[i][j];
            }
            if (sum != target) return false;
        }
        
        // Check all cols
        for(int j = c; j < c + k; j++) {
            int sum = 0;
            for(int i = r; i < r + k; i++) {
                sum += grid[i][j];
            }
            if(sum != target) return false;
        }

        // Check main dia
        int dia1 = 0;
        for(int i = 0; i < k; i++) {
            dia1 += grid[r + i][c + i];
        }
        if (dia1 != target) return false;
        
        int dia2 = 0;
        for(int i = 0; i < k; i++) {
            dia2 += grid[r + i][c + k - 1 - i];
        }
        if(dia2 != target) return false;
        
        return true;
    }
    
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 2; i + k <= n && j + k <= m; k++) {
                    if (isMagic(i, j, k, grid))
                    ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};

// ******************************************************OPTIMIZED****************************************
// ART!!!!, see how we used row, col, d1, d2 and initialized them, then filled there values in one loop, 
class Solution {
    public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> row(n, vector<int>(m + 1, 0));
        vector<vector<int>> col(n + 1, vector<int>(m, 0));
        vector<vector<int>> d1(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> d2(n + 1, vector<int>(m + 1, 0));

        // prefix sums
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j] = d2[i][j + 1] + grid[i][j];
            }
        }

        int ans = 1;

        // try largest k first (pruning)
        for(int k = min(n, m); k >= 2; k--) {
            for(int i = 0; i + k <= n; i++) {
                for(int j = 0; j + k <= m; j++) {

                    int target = row[i][j + k] - row[i][j];
                    bool ok = true;

                    // rows
                    for(int r = i; r < i + k && ok; r++) {
                        if(row[r][j + k] - row[r][j] != target)
                            ok = false;
                    }

                    // cols
                    for(int c = j; c < j + k && ok; c++) {
                        if(col[i + k][c] - col[i][c] != target)
                            ok = false;
                    }

                    // diagonals
                    int diag1 = d1[i + k][j + k] - d1[i][j];
                    int diag2 = d2[i + k][j] - d2[i][j + k];

                    if(ok && diag1 == target && diag2 == target)
                        return k;
                }
            }
        }
        return ans;
    }
};