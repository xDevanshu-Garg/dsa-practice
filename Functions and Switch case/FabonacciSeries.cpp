#include <iostream>
using namespace std;

int fabonacci(int num){

    int a = 0;
    int b = 1;
    int ans;

    cout << a <<' ' << b <<' ';

    for (int i = 0; i < num-2; i++)
    {
        
        ans = a + b;
        a = b;
        b = ans;
        cout << ans <<' ';
    }
    

}

int main(){

    int num;
    cout << "Enter the number: ";
    cin >> num;
    
    cout<<  "Fabonacci series : ";
    fabonacci(num);

}