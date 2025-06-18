#include <iostream>
using namespace std;

void bubbleSort(int* arr , int n)
{
    //Base case
    if(n == 0 || n == 1) return;

    //Processing
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            swap(arr[i] , arr[i+1]);
        }
    }

    //RR
    bubbleSort(arr, n-1);
}

int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    int arr[n];

    // code to enter elements
    cout << "Enter " << n << " elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout<<"Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<' ';
    }

    return 0;
}