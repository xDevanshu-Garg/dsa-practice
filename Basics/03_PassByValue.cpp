#include <iostream>
using namespace std;

// This will not swap values as it is calling by values.
void Swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// This will swap the values as it is calling by refrence.
void SwapPointer(int *x, int *y) // Pointers are used to change address.
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Using refrence variable
void SwapRefrence(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

inline int moneyCal(int money, float factor = 1.04) //Factor is a default argument and it should be on right otherwise error will occur.
{
    return money * factor;
}

int main()
{
    // int a = 3, b = 9;

    // cout << "The orignal value of a is " << a << " and the value of b is " << b << endl;
    // Swap(a, b);
    // cout << "The values after normal swap of a is " << a << " and the value of b is " << b << endl;

    // SwapPointer(&a, &b); //& is used because our function accepts int star value means pointer and pointer doesn't hold integer it holds address.
    // cout << "The values after pointer of a is " << a << " and the value of b is " << b << endl;

    // SwapRefrence(a,b);
    // cout << "The values after using refrence variable of a is " << a << " and the value of b is " << b << endl;

// ***************************************IMPORTANT*****************************************

    int money = 100000;
    cout << "Your money is now: " << moneyCal(money) <<endl; //We don't need second argument as we already have value in formal argument
    cout << "Your money is now: " << moneyCal(money, 1.10); 

    // cout << "Your money is now: " << moneyCal(money) = 200000; 

    return 0;
}