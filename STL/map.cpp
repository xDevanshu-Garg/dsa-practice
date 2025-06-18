#include <iostream>
#include <map>
using namespace std;

int main()
{
    map <int , string> m;

    m[1] = "Devanshu";
    m[23] = "Garg";
    m[32] = "BEST";
    m[14] = "CODER";

    m.insert({5,"Hiiii"});

    cout<<"Before Erase: " <<endl;
    for(auto i:m){
        cout<<i.first <<' ' <<i.second <<endl;
    }cout<<endl;

    cout<<"After Erase: " <<endl;
    m.erase(5);
    for(auto i:m){
        cout<<i.first <<' ' <<i.second <<endl;
    }cout<<endl;


    return 0;
}