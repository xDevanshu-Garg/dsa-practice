#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {3,2,7,5,6};
    int s = 0, e = 4;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    for(int i:arr){
        cout<<i <<' ';
    }cout<<endl;

    //Now for vector

    vector <int> v = {32,23,53,12,62,28};
    s = 0; e = v.size()-1;
    while(s<e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    for(int i =0;i<v.size(); i++){
        cout<<v[i] << ' ';
    }

    return 0;
}