#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(string digit, int index, vector<string> &ans, string output)
{
    vector<string> Map= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int number = int(digit[index] - '0');
    string s = Map[number];
    //Base Case
    if (index >= digit.length())
    {
        ans.push_back(output);
        return;
    }
    
    //RR
    
    for (int i = 0; i < s.length(); i++)
    {
        output.push_back(s[i]);
        solve(digit, index+1, ans, output);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    string output = "";
    int index = 0;
    vector<string> ans;
    
    solve(digits, index, ans, output);
    return ans;
}

int main()
{
    string input = "23";
    vector<string> result = letterCombinations(input);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i] << " ";
    }
    return 0;
}