#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //creation
    unordered_map<string, int> m;

    //insertion

    //1 
    pair<string, int> p1("abc", 1);
    m.insert(p1);

    //2
    pair<string, int> p2 = {"xyz", 2};
    m.insert(p2);

    //3
    m["ijk"] = 2; //Here we made a new entry of ijk cuz it's their first appreance
    m["ijk"] = 5; //Here we updated the value of ijk cuz it's already present in map

    //Search
    cout << m["ijk"] << endl;
    cout << m.at("ijk") << endl; //at will throw an error if key is not present while map will create a new entry with value 0

    //Search for non-existing key
    // cout << m.at("non-existing") << endl; //This will throw an error
    cout << m["non-existing"] << endl; //This will create a new entry with value 0
    cout << m.at("non-existing") << endl; //Now this will not throw an error. Why? Because we already created a new entry with value 0 when we used m["non-existing"]

    //Size
    cout << "size: " << m.size() << endl;

    //Check if empty
    cout << (m.empty() ? "Map is empty" : "Map is not empty") << endl;

    //count: Gives 1 if key is present else 0 ***IMP***
    cout << m.count("xyz") << endl; //1, It doesn't matter how many times we insert the same key, it will always return 1
    cout << m.count("non-non-existing") << endl; //0

    //Erase
    m.erase("xyz");
    cout << "Size after Deleting a key: " << m.size() << endl; //Size will be 3 now

    //Find: Returns an iterator to the element if found else returns end iterator
    auto it = m.find("ijk");
    if (it != m.end())
        cout << "Found: " << it->first << " " << it->second << endl;
    else 
        cout << "Not Found" << endl;
    
    //Iterate: .begin() and .end() will give iterators to the first and last element respectively and first and second will give the first and second element directly use -> while using first and second because it is an pointer to pair
    
    cout << "Iterating through the map:" << endl;
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << endl;

    //OR
    //Range based for loop
    cout << "Iterating using range based for loop:" << endl;
    for (auto& pair : m)
        cout << pair.first << " " << pair.second << endl;
    
    //Clear: Will clear the map
    m.clear();
    cout << "Size after clearing: " << m.size() << endl; //Size will be 0 now

    return 0;
}