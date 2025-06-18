// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
#include <iostream>
using namespace std;

// string removeOccurrences(string s)
// {
//     for (int i = 0; i < s.length() - 2; i++)
//     {
//         if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
//         {
//             s.replace(i, 3, "");
//             i = 0;
//         }
//     }
    
//     return s;
    
// }

// int main()
// {
//     string s = "daabcbaabcbc";

//     cout<< removeOccurrences(s);

//     return 0;
// }

int main()
{
    string s = "daabcbaabcbc", part = "abc";
    s= "dhfaj";
    cout<< s.find(part);

    // while (s.length() != 0 && s.find(part) <=0)
    // {
    //     s.erase(s.find(part), part.length());
    // }
    
}