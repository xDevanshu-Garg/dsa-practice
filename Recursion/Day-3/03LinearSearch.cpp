#include <iostream>
using namespace std;

bool LinearSearch(int *arr, int n, int target)
{   
    //Base Case
    if (n == 0) return false;
    
    //Processing
    if (*arr == target) return true;
    
    //RR
    return LinearSearch(arr+1, n-1, target);
}

int main()
{
    int arr[] = {2, 5, 7, 9, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout<<"Which element do you wanna find: ";
    cin>>target;

    if (LinearSearch(arr, size, target))
        cout << "Element is present!";
    else
        cout << "Element is abesent";

    return 0;
}