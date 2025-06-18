// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <iostream>
using namespace std;

void Posiition(int arr[], int n)
{
    int target;
    cout << "Enter the element you wanna find: ";
    cin >> target;

    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    cout<< first <<" " << last;
}
int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    int arr[n];

    // code to enter elements
    cout << "Enter " << n << " elements in assending order in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Posiition(arr, n);

    return 0;
}