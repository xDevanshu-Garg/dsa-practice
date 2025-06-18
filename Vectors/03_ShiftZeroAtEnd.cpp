#include <iostream>
using namespace std;

void shiftZeroAtEnd(int arr[], int n)
{
    int i = 0, j = 0;
    for (int j = 0; j < n; j++)    
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main()
{
    int arr[7] = {1, 0, 2, 5, 0, 4, 7};

    shiftZeroAtEnd(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}