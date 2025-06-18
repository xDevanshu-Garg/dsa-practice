#include <iostream>
using namespace std;

int partition(int*arr, int s, int e){

    int pivot = arr[s];
    //step1 count how many elements are less then pivot
    int count = 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot) count++;
    }
    int pivotIndex = s+count;
    swap(arr[s], arr[pivotIndex]); //Move pivot to it's right posn

    //Step 2 Make sure that all elements left to the pivot are smaller and right once are greater then pivot.
    int i = s, j = e;
    while(i< pivotIndex && j > pivotIndex){
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if(i < pivotIndex && j > pivotIndex) swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int* arr, int s, int e)
{
    //Base Case
    if(s >= e) return;

    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
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

    quickSort(arr, 0, n-1);

    cout<<"Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<' ';
    }
    delete[] arr;

    return 0;
}