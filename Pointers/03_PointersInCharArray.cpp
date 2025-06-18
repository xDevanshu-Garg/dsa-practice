#include <iostream>
using namespace std;

int main()
{
    char ch[6] = "abcde";

    cout << ch << endl; // In the case if int type array. Name of array represents the memory location of first element but in case of char array cout will print the entire char array. cout works differently for int type array and char type array.

    char *c = &ch[0]; // Points to the address of first block.
    cout << c << endl;
    // cout is desined for char array like: print all char untill '\0' null char is found.

    char a = 'a';
    char *p = &a;
    cout << p << endl;
    cout << &a;
    cout << &ch;

    return 0;
}