#include <iostream>
using namespace std;

int fact(int a){
    int fact = 1;
    for(int i = 1; i <= a; i++){
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r){

    int ans;

    ans = fact(n) / (fact(r) *  fact(n - r));

    return ans;

}

int main(){

    int n,r;
    cout<<"Enter the value of n and r ";
    cin>> n >> r;

    cout<<  "The value of nCr is: "<< nCr(n,r);

    return 0;
}