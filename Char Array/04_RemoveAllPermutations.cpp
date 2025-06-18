// https://leetcode.com/problems/permutation-in-string/description/
#include <iostream>
using namespace std;

bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}
bool checkPermutation(string s1, string s2)
{
    int count1[26] = {0};

    // Counting occurance of s1
    for (int i = 0; i < s1.length(); i++)
    {
        count1[s1[i] - 'a']++;
    }

    // Now counting for s2 in range of s1
    int count2[26] = {0};
    int i = 0;
    while (i < s1.length())
    {
        count2[s2[i] - 'a']++;
        i++;
    }

    if (checkEqual(count1, count2))
    {
        return 1;
    }

    while (i < s2.length())
    {
        count2[s2[i - s1.length()] - 'a']--;
        count2[s2[i] - 'a']++;
        i++;
        if (checkEqual(count1, count2))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    string s1 = "ab", s2 = "eidbaooo";

    cout << checkPermutation(s1, s2);
    return 0;
}