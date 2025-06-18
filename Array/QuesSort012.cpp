#include <iostream>
using namespace std;

int sort01(int arr[], int n){
    int count = 0, arr1[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            arr1[count] = arr[i];
            count++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            arr1[count] = arr[i];
            count++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 2)
        {
            arr1[count] = arr[i];
            count++;
        }
    }
    //to print
     for (int i = 0; i < n; i++)
    {
        arr[i] = arr1[i];
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] << ' ';
        
    }
        
}

int main(){

    int arr[15] = {0,1,1,2,1,2,0,1,2,1,2,0,1,0,2};

    sort01(arr, 15);

}


// // two pointer approch!!

// #include <iostream>
// using namespace std;

// int sort01(int arr[], int n){
    
//     int i=0, j=(n/3)-1,k=n-1;
//     while (i<j &&  j<k)

//     {
//         if (arr[i] == 0)
//         {
//             i++;
//         }
//         if (arr[k] == 2)
//         {
//             k--;
//         }

//         if (arr[j] == 1)
//         {
//             j++;
//         }

//         if (arr[i] == 1 && arr[j] == 0)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j++;
//         }
//         if (arr[i] == 2 && arr[k] == 0)
//         {
//             swap(arr[i], arr[k]);
//             i++;
//             k--;
//         }
//         if (arr[j] == 2 && arr[k] == 1)
//         {
//             swap(arr[j], arr[k]);
//             j++;
//             k--;
//         }

//         if (arr[i] == 1 && arr[j] == 2)
//         {
//             swap(arr[i], arr[j]);
//             i++;
//             j++;
//         }
//         if (arr[i] == 2 && arr[k] == 0)
//         {
//             swap(arr[i], arr[k]);
//             i++;
//             k--;
//         }
//         if (arr[j] == 2 && arr[k] == 1)
//         {
//             swap(arr[j], arr[k]);
//             j++;
//             k--;
//         }
        
        
        
        
//     }
    
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i] << ' ';

//     }
    
// }

// int main(){

//     int arr[15] = {0,1,1,2,1,2,0,1,2,1,2,0,1,0,2};

//     sort01(arr, 15);

// }