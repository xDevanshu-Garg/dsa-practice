#include <iostream>
using namespace std;

int BinarySearch(int *arr, int target, int start, int end)
{
    // Base Case
    if (start > end)
        return -1;

    // Processing
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        BinarySearch(arr, target, mid + 1, end);
    else
        BinarySearch(arr, target, start, mid - 1);
}

int main()
{
    int arr[] = {2, 5, 7, 9, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Which element do you wanna find: ";
    cin >> target;

    int ans = BinarySearch(arr, target, 0, size - 1);
    if (ans == -1)
        cout << "Element not found!";
    else
        cout << "Element is present at: " << ans;

    return 0;
}