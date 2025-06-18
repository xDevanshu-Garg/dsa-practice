#include <iostream>
using namespace std;

int selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
    return 0;
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
    }
    
}

int main()
{
    int arr[10] = {52, 96, 31, 63, 1, 8, 54, 23, 56, 32};
    selectionSort(arr, 10);
    printArr(arr, 10);
    return 0;
}

