// #include <iostream>
// using namespace std;

// int uniqueElement(int arr[], int n){

//     int target = 0;

//     while(target < n){

//     int count = 0;

//         for (int i = 0; i < n; i++)
//         {

//              if (arr[target] == arr[i] && target != i)
//              {
//                 count++;
//              }
//         }
//         if (count == 0)
//              {
//                return arr[target];
//              }

//         target++;
//     }
//     return 0; //means no unique element
// }

// int main(){
//     int n;
//     cout<<"Enter size of Array: ";
//     cin>>n;

//     int arr[n];

//     //code to enter elements
//     cout<<"Enter " <<n << " elements in the array: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin>> arr[i];
//     }

//     cout << uniqueElement(arr, n);
    
//     return 0;
// }


//Using XOR(^) gate

#include <iostream>
using namespace std;

int uniqueElement(int arr[], int n){

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result = result^arr[i];
    }
    return result;
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

    cout << uniqueElement(arr, n);
    
    return 0;
}