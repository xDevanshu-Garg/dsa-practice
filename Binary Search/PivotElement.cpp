#include <iostream>
using namespace std;

int Pivot(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid]>arr[0])
        {
            low = mid + 1;
        }
        else{
            high = mid;
        }
        
    }
    return low;
}

int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    int arr[n];

    // code to enter elements
    cout << "Enter " << n << " elements in assending order then in decending order in the array: "; 
    // Eg: 8 10 17 1 3 return index 3

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Pivot(arr, n);

    return 0;
}