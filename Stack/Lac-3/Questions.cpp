//! Next Smaller Element : https://bit.ly/34GjYL4
/*
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // ****************************Brute Force**********************************
    /*
    for(int i = 0; i<arr.size(); i++){
        bool isFound = false;
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i] > arr[j]){
                arr[i] = arr[j];
                isFound = true;
                break;
            }
        }
        if(!isFound) arr[i] = -1;
    }
    return arr;
    /*

    //***************************optimized using stack*************************
    stack<int> s;
    s.push(-1);

    for(int i = n-1; i >= 0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        //ans is stack ka top
        arr[i] = s.top();
        s.push(curr);
    }
    return arr;
}
*/

//! Largest Rectangular Area in Histogram: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

/*
class Solution {
public:
    vector<int> nextSmallerElement(vector<int> next, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        int curr = 0;

        for(int i = n-1; i>=0; i--){
            curr = i;
            while(s.top() != -1 && next[s.top()] >= next[i]){
                s.pop();
            }
            //we have our minimum element
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> prev, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            while(s.top() != -1 && prev[s.top()] >= prev[i]){
                s.pop();
            }
            //we have our minimum element
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //Creating 2 arrays of next and prev smaller elements
        vector<int> next;
        vector<int> prev;

        next = nextSmallerElement(heights, n);
        prev = prevSmallerElement(heights, n);
        //Now we want to apply our formula
        int max = 0;
        for(int i = 0; i<n; i++){
            int l = heights[i];
            //This is necessary if next is -1 means it is at n if prev is at -1 means automatically it is at -1
            if(next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            if(area > max) max = area;
        }
        return max;
    }
};
// TC is O(n*m) and SC is O(m)
*/