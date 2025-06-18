// https://www.naukri.com/code360/problems/print-like-a-wave_893268
#include <iostream>
using namespace std;

void wavePrint(int arr[][4], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            if (i%2 == 0)
            {
                cout << arr[j][i]<<' ';
            }
            else{
                cout << arr[n-1-j][i]<<' ';   
            }
        }
    }
}


int main()
{
    int arr[3][4];
    int n = 3, m = 4;
    cout << "Enter Elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Your array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << "After converting in wave: " << endl;
    wavePrint(arr, n, m);

    return 0;
}