#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Fixed starting point with variable ending points.
//******************************************MEMOIZATION***********************************************
// dp[i][j1][j2] = maximum cherries from row i when robot-1 is at j1 and robot-2 is at j2
// solve(i, j1, j2) = maximum cherries from row i to last row, assuming robot-1 is at (i, j1) and robot-2 is at (i, j2)
class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        //Base Cases
        int n = grid.size(), m = grid[0].size();
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return -1e8;

        if(i == n-1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1 ; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {

                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];

                value += solve(i+1, j1+dj1, j2+dj2, grid, dp);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // 3 parameters i,j1,j2 with max values of n,m,m respectively
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    
        return solve(0, 0, m-1, grid, dp);
    }
};

// Number of states are n*m*m
// For each state we're doing 9 operations
// so TC = O(n*m*m) * 9 
// for n,m max value can be 70 so 70*70*70*9 = 3Million
// SC = 70*70*70 * 4(int) = 1.3 MB

// *************************************************TABULATION**************************************************

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1 ; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m)
                                value += dp[i+1][j1+dj1][j2+dj2];
                                else 
                                value += -1e8;

                            maxi = max(maxi, value);
                        }
                    }
                    
                    dp[i][j1][j2] = maxi;
                    
                }
            }
        }
        
        return dp[0][0][m-1];    
    }
};

// Time: O(n * m * m * 9)

// Space: O(n * m * m)


// *********************************************SPACE OPTIMIZED**********************************************

//1D dp -> 2 variables
//2D dp -> 1D array
//3D dp -> 2D array

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> prev(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));

        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2) prev[j1][j2] = grid[n-1][j1];
                else prev[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {

                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1 ; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {

                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];

                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m)
                                value += prev[j1+dj1][j2+dj2];
                            else 
                                value += -1e8;

                            maxi = max(maxi, value);
                        }
                    }

                    curr[j1][j2] = maxi;
                    
                }
            }
            prev = curr;
        }

        return curr[0][m-1];    
    }
};

// Time: O(n * m * m * 9)
// Space: O(2* m * m)