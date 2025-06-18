#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n){

    int temp;


    for (int i = 0; i < n-1; i++)
    {

        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        
        }
        
    }

    cout<<"Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<' ';
    }
    
}

int main(){
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;

    int arr[n];

    //code to enter elements
    cout<<"Enter " <<n << " elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }

    bubbleSort(arr, n);
    
    return 0;
}