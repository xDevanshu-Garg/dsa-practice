#include <iostream>
using namespace std;

inline int getMax(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = 5, b = 10;
    // cout << (a > b) ? a : b; We can write like this but when we write this line multiple time we have to think everytime what this code is doing. So to increase readability we use funtions. But funtions are expensive to use. Why? Because firstly they create there own memory(can be avoided by using refrence variable). But main issue is performace because of time taken in funtion call then matching of arguments (funtion call overhead).
    cout << getMax(a, b) <<endl;

    a = 11, b = 2;
    cout << getMax(a, b) <<endl;

    //if there is only one line then compiler will definitely create inline funtion
    // If 2-3 lines compiler will decide wether to convert or not
    // 3 or more: Will not convert

    return 0;
}