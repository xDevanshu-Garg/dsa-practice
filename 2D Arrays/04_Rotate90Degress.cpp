#include <iostream>
using namespace std;

void rotate90(int arr[][4], int row, int col){

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col -1;

    int count = 0, total = row*col;

    while (count<total)
    {
        
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
    cout << "After converting in spiral: " << endl;
    rotate90(arr, n, m);

    return 0;
}