#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {3, 5, 4, 7, 8};

    int* p = arr;   //arr holds the address of first element so no & is needed

    cout<<*p <<endl;   //Prints the first element of the array.
    cout<<*(p+4)<<endl;   //Prints the last element of the array.

    // *******************VERY IMPORTANT******************

    cout<<*(p++)<<endl;   //Prints the first element of the array and then increment value by 1.
    cout<<*(p) <<endl;  //Prints the second element of the array.


    return 0;
}

