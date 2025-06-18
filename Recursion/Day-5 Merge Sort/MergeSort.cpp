#include <iostream>
using namespace std;

void Merge(int* arr, int s, int e)
{
    //Creating 2 arrays
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1, len2 = e - mid;
    
    int *first = new int[len1];
    int *second = new int[len2];
    

    //copying in both arrays
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    // mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    
    //merge 2 sorted arrays.
    int index1 = 0 , index2 = 0;
    mainArrayIndex = s;
    while(index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    // If length of first array is greater then second, so some elements are left in array one
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    //For remaing elements of second array
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    
    delete[] first;
    delete[] second;

}

void MergeSort(int* arr , int s, int e)
{
    //Base case
    if(s==e) return;
    
    //Processing
    int mid = s + (e-s)/2;

    //RR
    MergeSort(arr, s, mid);
    MergeSort(arr, mid +1, e);
    Merge(arr, s, e);
}

int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    int* arr = new int[n];

    // code to enter elements
    cout << "Enter " << n << " elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    MergeSort(arr, 0, n-1);

    cout<<"Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<' ';
    }
    delete[] arr;

    return 0;
}