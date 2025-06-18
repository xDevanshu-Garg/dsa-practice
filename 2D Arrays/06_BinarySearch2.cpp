// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
#include <iostream>
using namespace std;
bool BinarySearch(int matrix[][5], int target, int row, int col){
    int rowIndex = 0, colIndex = col-1;

    while (rowIndex<=colIndex)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
        {
            return true;
        }
        else if (element < target)
        {
            rowIndex++;
        }
        else{
            colIndex--;
        }        
    }
    return false;
}

int main()
{
    int matrix[5][5] = {1, 4, 7, 11, 15, 2, 5, 8, 12, 19, 3, 6, 9, 16, 22, 10, 13, 14, 17, 24, 18, 21, 23, 26, 30};
    int target = 15;

    cout<<BinarySearch(matrix,target,5,5);

    return 0;
}