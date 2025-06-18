#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   
    stack<int> s;
    s.push(2);
    s.push(3);

    s.pop();
    cout<<"Top element of the stack is: " <<s.top() <<endl;
    cout<<"Is stack empty: " << s.empty() <<endl;
    cout<<"Size of stack is: " << s.size() <<endl;

    return 0;
}