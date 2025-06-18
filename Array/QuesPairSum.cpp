#include<iostream>
using namespace std; //[https://bit.ly/3EwlU6e ]

int pairSum(int arr[], int n){

    for (int i = 0; i < n; i++)
    {
        
        for (int j = i+1;  j < n; j++){
            
            if (arr[i] + arr[j] == 0)
            {
                cout<< arr[i] << ' ' << arr[j] <<endl;
            }
            
        }

    }
    
}

int main(){

int arr[5]  = {2, -3, 3, 3, -2};

pairSum(arr, 5);

return 0;
}