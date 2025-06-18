#include <iostream>
using namespace std;

int main()
{
    int num = 5;
    int *p = &num; //here * tells that p is a pointer. And only pointer can store an address value.
    
    cout<<"P: " <<p<<endl;
    cout<< "Value at p: "<<*p <<endl; //Derefrence or value at operator.

    int *q;  //Don't leave vectors initialized without giving them where to point. It will now store an address that's not even in out memory.
    cout<<q <<endl;

    int *r = 0; //Instead initialize with 0 or null pointer.

    //Now if we want to assign an address later in r we do this.
    r = &num; //Don't write *again it's only to declear pointer.

    cout<<"r is: " <<r <<endl; //As you can see in output as well that p and r are pointing to the same memory location.
    cout<<"value at r is: " <<*r<<endl;

    (*r)++; //It will increment num as well
    cout<<num<<endl;
    r++; //It will increment it's address. In this case r is an int type pointer so it will increment by 4.
    cout<<r<<endl;

    //A pointer stores an address so it will take 8 bytes in size. 
    cout<<"Size of num: "<<sizeof(num) <<endl;
    cout<<"Size of pointer: "<<sizeof(r);


    return 0;
}