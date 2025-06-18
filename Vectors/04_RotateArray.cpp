//https://leetcode.com/problems/rotate-array/description/
#include <iostream>
using namespace std;

void rotateArray(int nums[], int n, int k){
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[(i+k)%n] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
    }
    
    
}       

int main()
{
    int nums[] = {1,2,3,4,5,6,7}, k = 3;

    rotateArray(nums,7,k);

    return 0;
}