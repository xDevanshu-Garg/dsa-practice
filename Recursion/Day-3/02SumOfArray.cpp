#include <iostream>
using namespace std;

int sum(int arr[], int n){
    
    //Base Case
    if (n == 0) return 0;
    if (n == 1) return *arr;
    
    //RR
    return *arr + sum(arr+1, n-1);

}

int main()
{
    int arr[] = {2, 5, 7, 9, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Sum of array is: " << sum(arr, size);

    return 0;
}