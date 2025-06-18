// #include <iostream>
// using namespace std;

// int sort01(int arr[], int n){
//     int count = 0, arr1[n];
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             arr1[count] = arr[i];
//             count++;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 1)
//         {
//             arr1[count] = arr[i];
//             count++;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout<< arr1[i] << ' ';
        
//     }
        
// }

// int main(){

//     int arr[10] = {0,1,1,1,0,1,1,0,1,0};

//     sort01(arr, 10);

// }


// two pointer approch!!

#include <iostream>
using namespace std;

int sort01(int arr[], int n){
    
    int i=0, j=n-1;
    while (i< j)
    {
        if (arr[i] == 0)
        {
            i++;
        }
        if (arr[j] == 1)
        {
            j--;
        }
        if (arr[i] == 1 && arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        
    }
    
    for (int i = 0; i < n; i++)
        {
            cout<< arr[i] << ' ';
            
        }
        
}

int main(){

    int arr[10] = {1,1,0,0,0,0,1,0};

    sort01(arr, 8);

}