#include <iostream>
using namespace std;

int update(int updatedArray[], int size){
    cout<< "Inside the array" <<endl;

    updatedArray[0]= 120;        //Here dinamic updation happens because arr name contains address of it's first element and here we're changin the address so it'll update the orignal value aswell
    
    for(int i = 0; i<3; i++){
        cout<< updatedArray[i] << ' ';
    }
    cout <<endl;

    cout<< "Going Back to main fn" <<endl;

}

int main(){

    int arr[3] = {2,4,6};

    update(arr, 3);

    for(int i = 0; i<3; i++){
        cout<< arr[i] << ' ';
    }


    return 0;
}