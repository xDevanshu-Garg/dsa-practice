// #include <iostream>
// using namespace std;

// int factorial(int n){

//     if (n<=1)
//     {
//         return 1;
//     }

//     return n * factorial(n-1);
// }

// int main()
// {
//     int a;
//     cout<<"Enter a number: ";
//     cin>>a;

//     cout<< factorial(a);

//     return 0;
// }

#include <iostream>
using namespace std;

void fabonacci(int n, int num1, int num2)
{

    int sum;
    sum = num1 + num2;
    num1 = num2;
    num2 = sum;
    cout << sum << ' ';
    if (n > 1)
    {
        fabonacci(n - 1, num1, num2);
    }
}

int main()
{
    int num1 = 0;
    int num2 = 1;

    int a;
    cout << "Enter a number: ";
    cin >> a;

    fabonacci(a, num1, num2);

    return 0;
}
