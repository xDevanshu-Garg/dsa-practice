//https://leetcode.com/problems/search-a-2d-matrix/
#include <iostream>
using namespace std;

int BSearch(int arr[][4], int target, int row, int col)
{
    int s = 0, e = (row * col) - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        int newRow = mid / col;
        int newCol = mid % col;
        if (arr[newRow][newCol] == target)
        {
            return mid;
        }
        else if (arr[newRow][newCol] >= target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int n = 3, m = 4, tar;
    
    cout << "Enter the element do you wanna find: ";
    cin >> tar;
    cout << "Element is at index: " << BSearch(arr, tar, n, m);

    return 0;
}