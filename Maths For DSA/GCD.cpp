//Euclid's Algorithm
/*
GCD(a,b) = (a-b,a) //whichever no. is greater get's subtracted. If a=0 then b is ans and vice versa and if a = b then a and b are ans.
relation between LCM and GCD is LCM(a,b) * GCD(a,b) = a*b
*/

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (a == 0)return b;
    if (b == 0) return a;

    while (a != b)
    {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

int main()
{
    int a, b;
    cout << "Enter two number: ";
    cin >> a >> b;
    cout << "GCD of " << a << " and " << b << " is " << GCD(a, b);

    return 0;
}