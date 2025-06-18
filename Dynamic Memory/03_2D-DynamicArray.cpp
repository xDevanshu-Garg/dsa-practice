#include <iostream>
using namespace std;

int main()
{
    //Creating a 2D-Dynamic array
    int n,m;
    cout<<"Enter Size of our 2D- array: ";
    cin>>n >>m;

    int** arr = new int*[n]; //Allocated rows.
    //now columns
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    cout<<"Allocated Successfully!!" <<endl;

    //now input
    cout<<"Input " <<n*m <<" elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    //Now printing
    cout<<"Elements in the array are: " <<endl;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cout<< arr[i][j] << " ";
        }
        cout<<endl;
    }

    //Freeing a  dynamically allocated 2D array

    for (int i = 0; i < n; i++)
    {
        delete[] arr[m];
    }
    delete[] arr[n];
    
    return 0;
}