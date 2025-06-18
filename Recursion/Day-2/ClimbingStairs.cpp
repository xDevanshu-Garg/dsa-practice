// https://leetcode.com/problems/climbing-stairs/
#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    // RR
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    
    cout<< climbStairs(5);

    return 0;
}