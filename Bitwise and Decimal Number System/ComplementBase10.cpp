#include <iostream>
using namespace std;

int compliment(int x)
{
    int mask = 0;
    int num = x;
    while(num != 0){
        num = num>>1;
        mask = (mask<<1) | 1;
    }
    x = ~x;
    int ans = x & mask;
    return ans;
}

int main()
{
    int x;
    cout << "Enter number you want to reverse: ";
    cin >> x;

    cout << compliment(x);
    return 0;
}