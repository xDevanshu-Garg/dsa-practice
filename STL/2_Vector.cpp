#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    cout<<"Size: " <<v.size() <<", Capacity: " <<v.capacity() <<endl;
    //When creating an empty vector both size and capacity is 0. Size referes to how many elements are there in the vector and capacity refers to how many elements a vector can stores. Every time vector's capacity overflows vector automatically doubles it's capacity to fit all the elements.

    v.push_back(2);
    cout<<"Size: " <<v.size() <<", Capacity: " <<v.capacity() <<endl;
    v.push_back(5);
    cout<<"Size: " <<v.size() <<", Capacity: " <<v.capacity() <<endl;
    v.push_back(7);
    cout<<"Size: " <<v.size() <<", Capacity: " <<v.capacity() <<endl; 
    v.push_back(6);
    v.push_back(4);
    cout<<"Size: " <<v.size() <<", Capacity: " <<v.capacity() <<endl;

    // ******************Accessing Elements of vector*********************

    cout<<"Element at index 2 is: " << v.at(2) <<endl;
    for(int i = 0; i<v.size(); i++){
        cout<<v.at(i) <<' ';
    }
    cout<<endl;

    cout<<"Element at front: " << v.front() <<endl;
    cout<<"Element at back: " << v.back() <<endl;

    v.pop_back();
    //Now vector
    cout<<"Element at index 2 is: " << v.at(2) <<endl;
    for(int i = 0; i<v.size(); i++){
        cout<<v.at(i) <<' ';
    }
    cout<<endl;
    v.clear(); //The size of vecor will be zero but capacity will retain same.
    cout<<"Size: " <<v.size() <<", Capacity: " <<v.capacity() <<endl;
 
    for(int i:v){
        cout<<i <<' ';
    } //It will print nothing
    cout<<endl;

    vector<int> v2(5,1); //The capacity and size of vector is 5 here. Without the second argument every value will be assigned with zero. Now all 5 vlaues are 1.

    for(int i:v2){
        cout<<i <<' ';
    }
    cout<<endl;

    // Coping a vector   
    vector<int> nakalchi(v2);
    
    for(int i:nakalchi){
        cout<<i <<' ';
    }
    cout<<endl;

    return 0;
}