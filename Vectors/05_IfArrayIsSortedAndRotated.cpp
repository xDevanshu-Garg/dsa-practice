// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
#include <iostream>
using namespace std;

bool checkRotation(int nums[])
{
    int n = 5;
    int i = 0, j = 1,k = 0;
    while(j<n){
        if(nums[i] <= nums[j]){
            i++, j++;
        }
        else{
            k = n-j;
            break;
        }
    }
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i+k)%n] = nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = temp[i];
    }
    bool isSorted = true;
    for (int i = 0; i < n-1; i++)
    {
        if (nums[i] <= nums[i+1])
        {
            continue;
        }
        else{
            isSorted = false;
        }
    }

    return isSorted;
    
}

bool checkRotation2(int nums[]){
    int n = 5;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i+1) % n]) count++;        
    }
    return count == 1;
        
}

int main()
{
    int nums[] = {3, 4, 5, 1, 2};

    cout<< checkRotation(nums) <<endl;
    cout<< checkRotation2(nums);

    return 0;
}