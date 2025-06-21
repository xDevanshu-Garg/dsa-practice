//! Celebrity Problem : https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
/*
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        //Base Case
        if(mat.size() == 1){
            return 0;
        }
        //Step1: Copy elements of array into stack
        stack<int> s;
        for(int i = 0; i< mat.size(); i++){
            s.push(i);
        }
        
        //Step2: while loop till size is 1
        while(s.size() > 1){
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            
            //Check if A knows B
            if(mat[A][B] == 0){
                s.push(A);
            }
            
            //if A is pushed means A doens't knows B means B can't be celeb
            else{
                s.push(B);
            }
        }
        
        //Step3: Single element = potiental Celebrity and we verify it by cheking if row is 0 and col is 1 except diagonal
        int celeb = s.top();
        for(int i = 0; i< mat.size(); i++){
            //skip diagonal
            if(celeb == i) continue;
            //for rows
            if(mat[celeb][i] != 0) return -1;
            //for col
            if(mat[i][celeb] != 1) return -1;
        }
        return celeb;
    }
};
*/

//! Max Rectangle in Binary Matrix with all 1's:https://leetcode.com/problems/maximal-rectangle/

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
            if(next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;
            int area = l * b;
            if(area > max) max = area;
        }
        return max;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> histogram(matrix[0].size(), 0);
        int area = 0;

        //Step1: Compute the area row wise and make histogram out of it.
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j< matrix[0].size(); j++){

//Check if curr row's ele is not 0 if it is then we will say entire col is 0
                if(matrix[i][j] == '1')
                    histogram[j] += 1;
                else
                    histogram[j] = 0;
            }
            // Step3: now compute the area of curr row i.e. curr = curr + prev row
            // and compute max from prev area and new area
            area = max(area, largestRectangleArea(histogram));
        }
        return area;
    }
};
*/