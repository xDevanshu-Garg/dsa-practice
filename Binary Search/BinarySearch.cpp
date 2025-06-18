#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n)
{
    int target;
    cout << "Enter the element you wanna find: ";
    cin >> target;

    int low = 0, high = n-1;

    while(low<=high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid]< target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
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
    cout << "Enter " << n << " elements in assending order in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<< BinarySearch(arr, n);

    return 0;
}