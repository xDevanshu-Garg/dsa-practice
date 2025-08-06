#include <iostream>
using namespace std;

int main(){
    int arr[10] = {2,5,4,1,9,5,0,8,4,7};
    
    //For Maximum element
    int maxx= INT_MIN;       //Gives Minimum value for 32 bits or 2^32
    int maxFn= INT_MIN;
    for(int i=0; i<10; i++){
        if(arr[i]>maxx){
            maxx = arr[i];
        }
        maxFn = max(maxFn, arr[i]);
    }
    cout<<"Maximum Element in the array is : "<<maxx <<endl;
    cout<<"Maximum Element in the array is : "<<maxFn <<endl;

    //For Minimum element
    int minn = INT_MAX;       ////Gives Maximum value for 32 bits or 2^32
    int minFn = INT_MAX;
    for(int i=0; i<10; i++){
        if(arr[i]<minn){
            minn = arr[i];
        }
        minFn= min(minFn, arr[i]);
    }
    cout<<"Minimum Element in the array is : "<<minn <<endl;
    cout<<"Minimum Element in the array is : "<<minFn <<endl;

    return 0;
    
}