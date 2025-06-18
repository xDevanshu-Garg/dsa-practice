#include <iostream>
using namespace std;

int reverse(int x) {
        int ans = 0, digit;
        while(x != 0){

            digit  = x%10;

            if(ans > (INT_MAX - digit)/10 || ans < (INT_MIN)/10){
                return 0;
            }
            else{
                ans = ans * 10 + digit;
                x = x/10;
                } 
        }

        x = ans;
        
            return x;
        
    }

int main()
{
    int x;
    cout<<"Enter number you want to reverse: ";
    cin>>x;

    cout<< reverse(x);

    return 0;
}