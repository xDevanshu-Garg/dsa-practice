#include <iostream> 
using namespace std;
int main (){

    int x;

    cout<<"Enter your amount: ";
    cin>> x;

    int value = 1;

    switch(value){

        case 1: cout<< x/100; 
        cout<< " notes of 100 you need" << endl;
        x = x%100;
        
        case 2: cout<< x/50;
        cout<< " notes of 50 you need" << endl;
        x = x%50;

        case 3: cout<< x/20;
        cout<< " notes of 20 you need" << endl;
        x = x%20;

        case 4: cout<< x/1;
        cout<< " notes of 1 you need" << endl;
        x = x%1;
    }

    return 0;
}