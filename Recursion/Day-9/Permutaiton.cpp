#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, int index, vector<vector<int>>& ans)
{
    //Base Case
    if (index+1 >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    
    //Processing
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);

        //RR
        solve(nums, index+1, ans);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    solve(nums, 0, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> result = permute(nums);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}