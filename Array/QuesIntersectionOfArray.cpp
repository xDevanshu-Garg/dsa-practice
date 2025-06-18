#include <iostream>
using namespace std; // for sorted array

int Intersection(int arr1[], int arr2[], int n1, int n2)
{

    int i = 0, j = 0;

    while (i < n1, j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i], arr2[j];
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n1, n2;
    cout << "Enter size of Array 1: ";
    cin >> n1;

    int arr1[n1];

    // code to enter elements
    cout << "Enter " << n1 << " elements in the array 1: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of Array 2: ";
    cin >> n2;

    int arr2[n2];

    cout << "Enter " << n2 << " elements in the array 2: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    Intersection(arr1, arr2, n1, n2);

    return 0;
}