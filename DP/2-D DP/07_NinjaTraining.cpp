#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//! Link: https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003

#include <bits/stdc++.h>
using namespace std;

//************************************ NINJA TRAINING - DP (Memoization) ************************************
// Problem: You are given points for 3 tasks each day. You can't do the same task on consecutive days.
// Goal: Maximize total points over 'n' days.

//---------------------------------- RECURSIVE FUNCTION WITH MEMOIZATION ----------------------------------
int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>>& dp) {

    // ********** BASE CASE **********
    // If it's the first day (day 0), choose the task that gives maximum points
    // except the one done on the previous day (denoted by 'last')
    if(day == 0) {
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last)
                maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    // ********** MEMOIZATION CHECK **********
    // If already computed, return the stored value
    if(dp[day][last] != -1)
        return dp[day][last];

    // ********** RECURSIVE CASE **********
    // Try all tasks for the current day except the last one
    int maxPoints = 0;
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + solve(day - 1, task, points, dp);
            maxPoints = max(maxPoints, point);
        }
    }

    // Store and return the result
    return dp[day][last] = maxPoints;
}

//------------------------------------------- MAIN FUNCTION -------------------------------------------
int ninjaTraining(int n, vector<vector<int>> &points) {

    // 2D DP array: size n x 4
    // 4 columns → 3 for tasks (0,1,2) + 1 extra (3) to indicate no task done before
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // Start recursion from last day (n-1) with last = 3 (no task constraint)
    return solve(n - 1, 3, points, dp);
}

//------------------------------------------- DRIVER CODE -------------------------------------------
int main() {
    int n = 3;
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "Maximum points: " << ninjaTraining(n, points) << endl;

    return 0;
}

/*
----------------------------------- REVISION NOTES -----------------------------------
🧠 CONCEPT:
- Each day → 3 possible tasks.
- You cannot perform the same task on consecutive days.
- Goal → maximize total points.

📘 RECURSION MEANING:
solve(day, last) = max points till 'day' if previous day's task = 'last'.

⚙️ TRANSITION:
solve(day, last) = max(points[day][task] + solve(day-1, task)) for all task ≠ last

🎯 BASE CASE:
For day = 0 → pick the maximum among all tasks except 'last'.

💾 DP TABLE:
dp[day][last] stores the max points till that day given last task.

⏱️ COMPLEXITY:
Time  → O(n * 4 * 3) ≈ O(n) n*4 is how much states we have and in each state we're doing 3 operations
Space → O(n * 4) (DP vector) + O(n) (recursion stack)

----------------------------------- END -----------------------------------
*/


//**************************************Tabulation******************************************/

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4,-1));
    dp[0][0] = max(points[0][1], points[0][2]);    
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            int maxPoints = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    maxPoints = max(maxPoints, point);
                }
            }
            dp[day][last] = maxPoints;
        }
    }
    return dp[n-1][3];
}

