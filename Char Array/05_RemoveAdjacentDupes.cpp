// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <iostream>
using namespace std;

string removeDuplicates(string s)
{
    for (int i = 0; i < (s.length()-1); i++)
    {
        if (s.empty()) break;
        if (s[i] == s[i+1])
        {
            s.erase(i,2);
            i=-1;
        }        
    }
    return s;
}

int main()
{
    string s = "aaaaaaaa";

    cout<<removeDuplicates(s);

    return 0;
}
