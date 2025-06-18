//https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <iostream>
using namespace std;

int Pivot(int nums[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;

        if (nums[mid]>=nums[0])
        {
            low = mid + 1;
        }
        else{
            high = mid;
        }
        
    }
    int temp = low; //It has the index of pivot element.
    // Now we have to search two times in 2 different arrays.

    int target;
    cout<< "Enter the element you wanna find: ";
    cin >> target;

    low = 0, high = temp - 1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    low = temp, high = n - 1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if (nums[mid] < target)
        {
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
    cout << "Enter " << n << " elements in assending order then in decending order in the array: "; 
    // Eg: 8 10 17 1 3 return index 3

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Pivot(arr, n);

    return 0;
}