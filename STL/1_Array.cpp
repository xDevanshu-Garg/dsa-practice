#include <iostream>
#include <array>
using namespace std;

int main()
{
    int basic[3] = {2, 3, 4};  //Static array

    array<int, 4> a = {22, 33, 44, 55}; 
    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout<<a[i] <<' ';
    }

    // int n = basic.size(); //Can't do this with normal array 

    cout<<endl <<"Element at Index 2: " << a.at(2) <<endl;
    cout<<"Is Array empty: " <<a.empty() <<endl;
    
    cout<<"First element: " <<a.begin() <<endl; //Returns adderess of first value in array if we want value we can use star('*').
    cout<<"First element: " <<a.front() <<endl;
    cout<<"Last element: " <<a.back();
    return 0;
}