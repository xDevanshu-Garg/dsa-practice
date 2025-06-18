#include <iostream>
using namespace std;

int MaximumRowWiseSum(int arr[][3], int row, int col)
{
    int maxi = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum+= arr[i][j];
        }
        maxi = max(maxi,sum);
    }
    return maxi;
}

int main()
{
    int arr[3][3];
    cout << "Enter Elements in the array: ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Your array is: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    cout<<"The maximum sum of rows are: "<<MaximumRowWiseSum(arr, 3, 3);

    return 0;
}