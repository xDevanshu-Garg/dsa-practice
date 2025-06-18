#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque <int> d;
    d.push_back(2);
    d.push_front(5);
    for(int i:d){
        cout<<i <<' ';
    }
    cout<<endl;

    cout<<"Element at index 1 is: " <<d.at(1) <<endl;
    cout<<"Element at front is: " <<d.front() <<endl;
    cout<<"Element at back is: " <<d.back() <<endl;
    cout<<"Deque empty or not: " <<d.empty() <<endl;
    cout<<"Size of deque is: " <<d.size() <<endl;

    // d.pop_back();
    // cout<<"Size of deque is: " <<d.size() <<endl;
    // d.pop_front();
    // cout<<"Size of deque is: " <<d.size() <<endl;

    d.erase(d.begin(), d.begin()+1);
    for(int i:d){
        cout<<i <<' ';
    }
    cout<<endl;


    return 0;
}