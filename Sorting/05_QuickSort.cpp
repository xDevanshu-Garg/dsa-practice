#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e) {
    int pivot = arr[s]; //chose start of array as pivot

    // Count how many elements are smaller then pivot 
    int count = 0; 
    for(int i = s+1; i <= e; i++) {
        if(arr[i] <= pivot) count++;
    }

    //Pivot index calculation and place pivot at right posn
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);
    
    //Now the pivot is in its final position, but the rest of the array is still messy, so fixing it by swapping 
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;

        if(i < pivotIndex && j > pivotIndex) 
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void QuickSort(int arr[], int s, int e) {
    //Base Case: If only one element left then return
    if(s >= e) return;

    int p = partition(arr, s, e);
    QuickSort(arr, s, p-1);
    QuickSort(arr, p+1, e);

}

int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    int arr[n];

    // code to enter elements
    cout << "Enter " << n << " elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    QuickSort(arr, 0, n-1);

    cout<<"Sorted Array: ";

    for (int i = 0; i < n; i++) {
        cout<<arr[i] <<' ';
    }

    return 0;
}

// 4 3 7 2 1 9 5 8 6

// 3 2 1   (4)   7 9 5 8 6
// 2 1 (3)    5 6 (7) 9 8
// 1 (2)     (5) 6   8 (9)