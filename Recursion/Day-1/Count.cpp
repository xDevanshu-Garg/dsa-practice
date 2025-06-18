#include <iostream>
using namespace std;

void count(int n){

    if (n == 0) return;
    
    // cout<< n << endl;

    count(n-1);

    cout<< n << endl;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    count(n);

    return 0;
}