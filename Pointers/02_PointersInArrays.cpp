#include <iostream>
using namespace std;

int main()
{
    // int arr[10] = {10,20,30};

    // // as we know that arr name is a pointer that stores the address of first element of the array
    // cout<<"Address of first element is: " << arr <<endl;
    // cout<<"Value of first element is: " << *arr <<endl;
    // //OR
    // cout<<"Value of first element is: " << arr[0] <<endl;
    // //From here we can see that arr[i] = *(arr+i)

    // // ******************IMP*********************

    // //i[arr] = *(i+arr)
    // cout<<"Value of third element is: " << 2[arr] <<endl;

    //**************Difference Between a ptr and name of array***********

    // int temp[5] = {1, 2, 3};
    // int *p = temp;

    // cout << "Size of array is: " << sizeof(temp) << endl;      // This will calc size of whole array.
    // cout << "Size of p is: " << sizeof(p) << endl;             // This'll show size to store an address which is 8 bytes.
    // cout << "Size of address of p is: " << sizeof(&p) << endl; // It will also be 8 bytes.

    int a[20] = {1, 2, 3, 5};

    cout << &a[0] << endl;
    cout << &a << endl;
    cout << a << endl;

    int *p = &a[0];
    cout << p << endl;
    cout << *p << endl;

    return 0;
}