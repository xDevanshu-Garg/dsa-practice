//normal reverse

/*
#include <iostream>
using namespace std;

int main(){
    int arr[10] = {2,5,4,1,9,5,0,8,4,7};
    
    for (int i=10; i>0 ; i--){
        cout << arr[i-1] <<' ';
    }

    return 0;
} */


//second method
#include <iostream>
using namespace std;

int main(){
    int arr[10] = {2,5,4,1,9,5,0,8,4,7};
    int temp;
    for (int i = 0; i < 10; i++)
    {
        if (i<=10-i)
        {
            temp =arr[i];
            arr[i] = arr[9-i];
            arr[9-i] = temp;
        }
    }

    cout<<"Reversed Array is: ";
    for (int i = 0; i < 10; i++)
    { 
        cout<<arr[i] <<' ';
    }
    
    
    return 0;
}