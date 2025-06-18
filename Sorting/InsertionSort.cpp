#include <iostream>
using namespace std;

int InsertionSort(int arr[], int n)
{

    // int i = 1, j = i - 1;

    // while (i < n && j >= 0)
    // {
    //     int temp = arr[i];

    //     if (arr[j] > arr[i])
    //     {
    //         arr[j + 1] = arr[j];
    //         j--;
    //     }
    //     else
    //     {
    //         arr[j+1] = temp;
    //         i++;
    //         j = i - 1;
    //         continue;
    //     }
    // }

    for (int j = 1; j < n; j++)
    {
        int key = arr[j];
        int i = j - 1;

        while ( i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    } 
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}

// void printArr(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << ' ';
//     }
// }

int main()
{
    int arr[10] = {10, 1, 7, 4, 8, 2, 11};
    InsertionSort(arr, 7);
    // printArr(arr, 7);

    return 0;
}