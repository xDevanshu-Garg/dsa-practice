#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input = "Devansh";

    stack<char> s;
    
    // Insert into stack
    for (char c: input)
        s.push(c);
    
    //pop 
    string ans = "";
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    
    cout<<"Ans is: " << ans <<endl;
    

    return 0;
}