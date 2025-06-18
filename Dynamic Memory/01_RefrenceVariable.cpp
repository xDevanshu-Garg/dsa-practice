#include <iostream>
using namespace std;

void update1(int a){
    a++;
}

void update2(int& a){
    a++;
}

// ********************************IMP*****************************
// these 2 funtions will generate warning because what they are returning is limited to funtion only. So they become dangling refrence and dangling pointers respectivley.And accessing them may result in unexpected behaviour.
int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
}

int* fun(int a){
    int* ptr = &a;
    return ptr;
}

int main()
{
    int a = 5;

    cout<<"Before a: " <<a<<endl;
    update1(a);
    cout<<"After a: " <<a<<endl;

    cout<<"Before a: " <<a<<endl;
    update2(a);
    cout<<"After a: " <<a<<endl;

    cout<<"Before a: " <<a<<endl;
    func(a);
    cout<<"After a: " <<a<<endl;

    fun(a);


    return 0;
}