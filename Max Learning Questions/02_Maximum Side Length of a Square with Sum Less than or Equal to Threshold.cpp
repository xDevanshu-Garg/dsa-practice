#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! In this ques, I learned how to use prefix sum for row and matrix, then how to apply BS too
//! https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

// ***************************************BRUTE FORCE with row Prefix sum************************************
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        // Prefix sum for row
        vector<vector<int>> row(n, vector<int>(m+1, 0));

        // Filling row 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row[i][j+1] = row[i][j] + mat[i][j];
            }
        }

        // Try larget k first (pruning)
        for(int k = min(n, m); k >= 1; k--) {
            for(int i = 0; i + k <= n; i++) {
                for(int j = 0; j + k <= m; j++) {
                    int sum = 0;
                    bool ok = true;
                    for(int r = i; r < i + k && ok; r++) {
                        sum += row[r][j+k] - row[r][j];
                        if(sum > threshold) 
                            ok = false;
                    }
                    if(ok) return k;
                }
            }
        }
        return 0;
    }
};
// This will TLE because O(N × N² × N) = O(N⁴) => 300⁴ = 8.1 × 10⁸ (TLE)
// We should optimize it further, we're iterating k times on row prefix sum so We must reduce square sum calculation to O(1).

// ************************************BETTER with matrix prefix sum*********************************************

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        // Prefix sum for matrix pref[i+1][j+1] = sum of matrix till i,j
        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));

        // Filling prefix matrix 
        // up + left - dia + curr (why - dia cuz it appeared 2 times in up and left so we -1 time so now we have 1left, 1up, 1dia, curr)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + mat[i][j];
            }
        }

        // Try larget k first (pruning)
        for(int k = min(n, m); k >= 1; k--) {
            for(int i = 0; i + k <= n; i++) {
                for(int j = 0; j + k <= m; j++) {
                    // sub both left and up but then dia is sub 2 times which is wrong our ans will be negative, so add 1 dia, i+k, j+k(curr) - 1up - 1left + 1dia
                    if(pref[i+k][j+k] - pref[i][j+k] - pref[i+k][j] + pref[i][j] <= threshold) 
                        return k;
                }
            }
        }
        return 0;
    }
};
// TC: k → O(N), (i, j) → O(N²), Sum check → O(1), total = O(N³) 
// We can improve it by finding k using BS

// *********************************OPTIMIZED using BS****************************************


class Solution {
public:
    int can (int k, vector<vector<int>>& pref, int n, int m, int threshold) {
        for(int i = 0; i + k <= n; i++) {
            for(int j = 0; j + k <= m; j++) {
                int sum = pref[i+k][j+k] - pref[i][j+k] - pref[i+k][j] + pref[i][j];
                if(sum <= threshold) 
                    return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        // Prefix sum for matrix pref[i+1][j+1] = sum of matrix till i,j
        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));

        // Filling prefix matrix 
        // up + left - dia + curr (why - dia cuz it appeared 2 times in up and left so we -1 time so now we have 1left, 1up, 1dia, curr)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + mat[i][j];
            }
        }

        // BS on k
        int low = 0, high = min(n, m);
        // Low is taken 0 cuz k can be 0 too, and k = 0 is always true, That gives us a guaranteed valid starting point. BS works best when you know at least one valid point.
        
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(can(mid, pref, n, m, threshold))
                low = mid + 1; // Successful so try bigger k
            else 
                high = mid - 1; // Unsuccessfull so try smaller k
        }
                
        return high; // Ans is at high, The loop stops when: low > high, so low points to min invalid, high points to max valid, we can return low-1 too.
    }
};

// TC =  O(N²logk), where k can be upto n,