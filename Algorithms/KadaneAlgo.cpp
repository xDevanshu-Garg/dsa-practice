#include <bits/stdc++.h>
using namespace std;

/*
    Kadane's Algorithm
    ------------------
    Finds the maximum sum of a contiguous subarray
    Time Complexity  : O(n)
    Space Complexity : O(1)
*/

int maxSubArraySum(vector<int> &arr) {
    int n = arr.size();

    // maxEndingHere -> max subarray sum ending at current index
    // maxSoFar      -> overall maximum subarray sum
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];

    for (int i = 1; i < n; i++) {
        // Either extend the previous subarray or start a new one
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);

        // Update the overall maximum
        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;
}

//Simple way
int maxSubArraySum2(vector<int> &arr) {
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int x: arr) {
        // Either extend the previous subarray or start a new one but include x not 0
        currSum = max(x, currSum + x);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Subarray Sum = " << maxSubArraySum(arr) << endl;
    cout << "Maximum Subarray Sum = " << maxSubArraySum2(arr) << endl;

    return 0;
}