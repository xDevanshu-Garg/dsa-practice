#include <iostream>
using namespace std;

void alternateSwap(int arr[], int n){

    cout<<endl <<"Array after swaping: ";
    for (int i = 0; i+1 < n; i+=2)
    {
        swap(arr[i], arr[i+1]);
    }
    
}

void printArray(int arr[], int n){

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
    cout<<"Enter 10 elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    
    //code to print elements
    cout<<"Array before swaping: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<' ';
    }

    alternateSwap(arr, n);
    printArray(arr, n);

    return 0;
}