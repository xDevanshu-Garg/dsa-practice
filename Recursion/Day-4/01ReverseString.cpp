// #include <iostream>
// using namespace std;

// string reverseString(string str, int s, int e)
// {
//     //Base case
//     if (s>e) return str;

//     //Processing
//     swap(str[s], str[e]);

//     //RR
//     return reverseString(str, s+1, e-1);
// }

// int main()
// {
//     string s;
//     cout<<"Enter a string: ";
//     getline(cin,s);
//     int start = 0, end = s.length()-1;
//     cout<< reverseString(s, start, end);

//     return 0;
// }

//Using Single Pointer to solve this problem 

#include <iostream>
using namespace std;

string reverseString(string str, int s)
{
    int e = str.length() -s -1;
    //Base case
    if (s>e) return str;

    //Processing
    swap(str[s], str[e]);

    //RR
    return reverseString(str, s+1);
}

int main()
{
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);
    cout<< reverseString(s, 0);

    return 0;
}