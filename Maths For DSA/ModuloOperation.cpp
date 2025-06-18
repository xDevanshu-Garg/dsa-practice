// https://www.naukri.com/code360/problems/modular-exponentiation_1082146
#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m)
{
    int ans = 1;
    for (int i = 0; i < n/2; i++)
    {
        ans = ans*x;
    }
    ans = ans * ans;
    if (n&1)
    {
        ans = ans*x;
    }
    ans = ans%m;
    return ans;
}

int main()
{
    int x, n, m;
    cout << "Enter a number, power and mod: ";
    cin >> x >> n >> m;

    cout<<modularExponentiation(x,n,m);

    return 0;
}