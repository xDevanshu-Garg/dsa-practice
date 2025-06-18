//https://leetcode.com/problems/subsets/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector <int>> &ans)
{
    //Base case
    if(index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    //RR
    //Exclude
    solve(nums, output, index+1, ans);
    // Include
    int element = nums[index];
    output.push_back(element);

    solve(nums, output, index+1, ans);
}

vector<vector<int>> subsets(vector<int> & nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    
    solve(nums, output, index, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j] <<", ";
        }
        cout<<endl;
    }
    return 0;
}