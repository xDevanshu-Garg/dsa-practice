#include<iostream>
using namespace std;

int main(){

    int a,b;
    cout << "Enter 2 numbers: ";
    cin>> a>>b;

    char op;
    cout <<"Which operation do you want to perform? ";
    cin >> op;

    switch(op){
        case '+': cout<< a+b; break;
        case '-': cout<< a-b; break;
        case '*': cout<< a*b; break; 
        case '/': cout<< a/b; break;
        default: cout << "Enter a valid option!";
    }

}