#include <iostream>
using namespace std;

int uniqueOccurence(int arr[], int n){
    int newarr[10];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; i < i; j++)
        {
            if (arr[i]^arr[j] == 0)
            {
                count++;
            }
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

    cout << uniqueOccurence(arr, n);
    
    return 0;
}