#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int target){
    for(int i = 0; i<10; i++){
        if(target == arr[i]){
        return 1;
        }
    }
    return 0;
}
int main(){
    int target;
    cout<< "Which element you want to find: ";
    cin>> target;
    int arr[10] = {2,5,4,1,9,55,0,8,77,7};
    cout<< LinearSearch(arr, 10, target);
    
    return 0;
}