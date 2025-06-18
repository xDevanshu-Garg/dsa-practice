#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int stringCompression(vector<char> chars)
{
    string s;
    int count = 1;
    if (chars.size() <= 1)
    {
        for (int i = 0; i < chars.size(); i++)
        {
            cout << chars[i];
        }
        return chars.size();
    }

    for (int i = 0; i < chars.size() - 1; i++)
    {
        if (chars[i] == chars[i + 1])
        {
            count++;
            continue;
        }
        s.append(1, chars[i]); // appends 1 time
        if (count > 1)
        {   
            s += to_string(count);
        }
        count = 1;
    }
    if (count > 1)
    {
        s.append(1, chars[chars.size() - 1]);
        s += to_string(count);
    }
    else{
        s.append(1, chars[chars.size() - 1]);
    }
    // cout << s;
    chars.clear();
    chars.resize(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        chars[i] = s[i];
    }

    for (int i = 0; i < chars.size(); i++)
    {
        cout << chars[i] << ' ';
    }

    return s.length();
}

int main()
{
    vector<char> chars = {'a', 'b', 'c'};

    stringCompression(chars);

    return 0;
}