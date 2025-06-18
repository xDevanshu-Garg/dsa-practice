// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
#include <iostream>
using namespace std;

int Peak(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid - 1] <= arr[mid] && arr[mid] >= arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid - 1] <= arr[mid] && arr[mid] <= arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }

    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    int arr[n];

    // code to enter elements
    cout << "Enter " << n << " elements in assending order then in decending order in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Peak(arr, n);

    return 0;
}