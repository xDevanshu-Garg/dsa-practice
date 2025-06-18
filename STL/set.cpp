#include <iostream>
#include <set>
using namespace std;

//it sortes element in sorted order

int main()
{
    set <int> s;
    s.insert(5);
    s.insert(2);
    s.insert(9);
    s.insert(5);    //No dups allowed so this will not be included.
    s.insert(8);

    cout<<"Size of set is: "<<s.size() <<endl;
    cout<<"Elements in the sets are: ";
    for(int i:s){
        cout<<i << ' ';
    }cout<<endl;

    

    return 0;
}