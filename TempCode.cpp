#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a = 2, b = 3;
    tie(a, b) = tie(b, a);
    cout<<"a: " <<a <<" b: " <<b;
    return 0;
}
