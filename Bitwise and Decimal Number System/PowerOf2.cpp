#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return (n-1 & n) == 0;
}


int main()
{
    int x;
    cout<<"Enter number you want to reverse: ";
    cin>>x;
    cout<< isPowerOfTwo(x);


    return 0;
}