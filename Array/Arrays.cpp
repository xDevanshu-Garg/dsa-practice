#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int firstArray[5];
    fill(firstArray, firstArray+5, 1);

    for (int i = 0; i < 5; ++i) {
        cout << firstArray[i] << " ";
    }
    cout <<endl;
    cout <<sizeof(firstArray)/sizeof(int);

    return 0;
    
}