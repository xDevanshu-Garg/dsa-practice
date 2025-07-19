#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string concatHex36(int n) {
        // first create mapping
        unordered_map<int , char> numToChar;
        for(int i = 0; i < 36; i++){
             if (i <= 9)
                numToChar[i] = '0' + i;   // '1' to '9'
            else
                numToChar[i] = 'A' + (i - 10);  // 'A' to 'F'
        }
        
        string ans = "";
        int num = n*n*n;

        while(num != 0){
            int digit = num % 36;
            ans = numToChar[digit] + ans;
            num = num/36;
        }

        num = n*n;
        while(num != 0){
            int digit = num % 16;
            ans = numToChar[digit] + ans;
            num = num/16;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ans = s.concatHex36(36) ;
    cout<<ans;

    return 0;
}