#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector <int> v{11, 34, 56, 67, 89};
    /*
    Lower Bound: The lower bound of a value in a sorted range is the position of the first element that is not less than the given value.
    If all elements in the container are smaller than the given value, it returns an iterator to the first element that is greater than or equal to the value.

    Upper Bound: The upper bound of a value in a sorted range is the position of the first element that is greater than the given value.
    It returns an iterator to the first element that is greater than the value. If no element is greater, it returns an iterator to the end.
    */

    cout<<"Lower Bound: " << *lower_bound(v.begin(),v.end(),30)<<endl; //Here we used value of/derefrencing operator(*) to derefrence an iterator which is being treated as a pointer.

    //When we subtract an iterator to iterator it returns index. 
    cout<<"Lower Bound: " << lower_bound(v.begin(),v.end(),30)-v.begin() <<endl;

    cout<<"Upper bound: "<<*upper_bound(v.begin(), v.end(),30) <<endl;

    int a = 5, b = 3;
    cout<<"Maximum from a and b:" <<max(a,b)<<endl;
    swap(a,b);
    cout<<"Swapping values. Now a: "<<a <<", b: "<<b <<endl;

    // sort(v.end(),v.begin()); this will sort out vector but it's already sorted.
    sort(v.begin(), v.end(), greater<int>()); //This will sort in decreasing order.

    cout<<"sorted vector: ";
    for(int i:v){
        cout<<i << ' ';
    }
    

    return 0;
}