#include <iostream>
using namespace std;

bool CheckPalindrome(string str, int s, int e)
{
    //Base Case
    if(s>e) return 1;
    
    //Processing
    if (str[s] != str[e]) return 0;

    //RR
    return CheckPalindrome(str, s+1, e-1);
    
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    cout << CheckPalindrome(s, 0, s.length() - 1);

    return 0;
}