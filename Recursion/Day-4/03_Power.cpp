// #include <iostream>
// using namespace std;

// int power(int a, int b)
// {
//     //Base case
//     if(b == 0) return 1;

//     //RR
//     return a * power(a,b-1);
// }

// int main()
// {
//     int a, b;
//     cout << "Enter number and it's power: ";
//     cin >> a >> b;

//     cout << power(a, b);

//     return 0;
// }

#include <iostream>
using namespace std;

int power(int a, int b)
{
    //Base case
    if(b == 0) return 1;
    if(b == 1) return a;

    //RR
    int ans = power(a,b/2);
    if (b%2 == 0) //even
    {
        return ans * ans;
    }
    else{
        return a * ans * ans;
    }
    
}

int main()
{
    int a, b;
    cout << "Enter number and it's power: ";
    cin >> a >> b;

    cout << power(a, b);

    return 0;
}