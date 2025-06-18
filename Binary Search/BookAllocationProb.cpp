#include <iostream>
using namespace std;

void Allocate(int arr[], int n)
{
    int maximum, minimum = INT_MAX;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum1 = sum1 + arr[j];
        }

        for (int j = 0; j < n - 1 - i; j++)
        {
            sum2 = sum2 + arr[j];
        }

        maximum = max(sum1, sum2);
        minimum = min(maximum, minimum);
    }
    cout<<minimum;
}

int main()
{
    int arr[4] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(int);

    Allocate(arr, n);

    return 0;
}