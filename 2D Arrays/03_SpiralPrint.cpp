// https://leetcode.com/problems/spiral-matrix/
#include <iostream>
using namespace std;

// void spiralPrint(int arr[][4], int row, int col)
// {
//     int n = 0, m = 0;
//     int total = row*col,count = 0;
//     while (count<total)
//     {
//         // For starting row
//         for (int i = n; i < col &&count<total; i++)
//         {
//             cout << arr[n][i] << ' ';
//             count++;
//         }
//         col--;
//         // for Ending col
//         for (int i = m+1; i < row &&count<total; i++)
//         {
//             cout << arr[i][col] << ' '; //change col-1
//             count++;
//         }
//         row--;
//         // for Ending row
//         for (int i = col - 1; i >= m &&count<total; i--)
//         {
//             cout << arr[row][i] << ' ';
//             count++;
//         }
//         n++;
//         // for Starting col
//         for (int i = row - 1; i >= n &&count<total; i--)
//         {
//             cout << arr[i][m] << ' ';
//             count++;
//         }
//         m++;
//     }
// }

// saaf saaf code
void spiralPrint(int arr[][4], int row, int col){
    //Indices
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col -1;

    int count = 0, total = row* col;

    while(count<total){
        //starting row ke liye
        for (int i = startingCol; i <= endingCol &&count<total; i++)
        {
            cout<<arr[startingRow][i] <<' ';
            count++;
        }
        startingRow++;
        
        //ending col ke liye
        for (int i = startingRow; i <= endingRow &&count<total; i++)
        {
            cout<<arr[i][endingCol] <<' ';
            count++;
        }
        endingCol--;

        // ending row ke liye
        for (int i = endingCol; i >= startingCol &&count<total; i--)
        {
            cout<< arr[endingRow][i] <<' ';
            count++;
        }
        endingRow--;

        //starting Col ke liye
        for (int i = endingRow; i >= startingRow &&count<total; i--)
        {
            cout<< arr[i][startingCol] <<' ';
            count++;
        }
        startingCol++;
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
    spiralPrint(arr, n, m);

    return 0;
}