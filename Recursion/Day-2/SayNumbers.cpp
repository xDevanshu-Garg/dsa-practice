#include <iostream>
using namespace std;

void sayNumber(int n, string arr[]){

    //Base Case
    if(n == 0) return;

    //processing
    int digit = n % 10;
    n = n/10;

    //RR
    sayNumber(n, arr);
    cout<<arr[digit] << " ";

}

int main()
{
    int n;
    cout<<"Enter digit: ";
    cin>>n;

    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    sayNumber(n, arr);

    return 0;
}