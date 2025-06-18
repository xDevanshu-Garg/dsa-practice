#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int arr[26] = {0};

    for (int i : s)
    {
        char ch = i;
        int number = 0;
        // lowercase
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else // uppercase
        {
            number = ch - 'A';
        }
        arr[number]++;
    }

    int maximum = arr[0];
    int index = 0;
    for (int i = 0; i < 25; i++)
    {
        if (maximum < arr[i+1])
        {
            maximum = max(maximum,arr[i+1]);
            index = i+1;
        }
    }
    
    cout<<"maximum is: "<<char(index + 'a');
    

    return 0;
}