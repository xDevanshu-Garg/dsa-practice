#include <iostream>
using namespace std;

int dupeElement(int arr[], int n){

    for(int i = 0; i<n; i++){

        for(int j = 0; j<n; j++){

            if(arr[i]^arr[j] == 0 && i!=j)
            return arr[i];
            
        }
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

    cout << dupeElement(arr, n);
    
    return 0;
}