#include <iostream>
using namespace std;

bool isSorted(int arr[], int n){
    
    //Base Case
    if(n == 0 || n == 1) return true;

    //Processing
    if (*arr > *(arr+1)) return false;
    
    //RR
    return isSorted(arr+1, n-1);    
}

int main()
{
    int arr[] = {2, 5, 7, 9, 12, 15};
    int size = sizeof(arr)/ 4;
    if(isSorted(arr, size)) cout<<"Array is sorted!";
    else cout<<"Array is not sorted";

    return 0;
}