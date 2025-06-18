#include<iostream>
using namespace std;

void Merge(int* arr, int s, int e)
{   
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int arr1[len1];
    int arr2[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k++];
    }
    int index1 = 0, index2 = 0;
    k = s;
    while(index1 < len1 && index2 < len2){
        if (arr1[index1] < arr2[index2])
        {
            arr[s++] = arr1[index1++];
        }
        else
        {
            arr[s++] = arr2[index2++];
        }        
    }
    while(index1 < len1){
        arr[s++] = arr1[index1++];
    }
    while(index2 < len2){
        arr[s++] = arr2[index2++];
    }

}

void MergeSort(int * arr, int s, int e)
{
    //Base Case
    if(s>=e) return;

    //Processing
    int mid = s + (e-s)/2;

    //RR
    MergeSort(arr, s, mid);
    MergeSort(arr, mid+1, e);
    Merge(arr, s ,e);
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

    MergeSort(arr, 0, n-1);

    cout<<"Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<' ';
    }

    return 0;
}