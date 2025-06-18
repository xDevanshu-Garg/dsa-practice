#include <iostream>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverseSetring(char name[])
{

    int start = 0, end = getLength(name) - 1;

    while (start < end)
    {
        swap(name[start++], name[end--]);
    }
    cout << "Reversed string: " << name << endl;
}

int checkPalindrome(char name[])
{
    int n = getLength(name);
    // Only aphaNumeric
    char temp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if ((48 <= name[i] && name[i] <= 57) || (65 <= name[i] && name[i] <= 90) || (97 <= name[i] && name[i] <= 122))
        {
            temp[j++] = name[i];
        }
    }
    temp[j] = '\0';
    for (int i = 0; temp[i] != '\0'; i++)
        {
            name[i] = temp[i];
        }
    name[j] = '\0';

    // converting into lowercase
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (65 <= name[i] && name[i] <= 90)
        {
            name[i] = char(name[i] + 32);
        }
    }
    
    //Now checking
    int start = 0, end = getLength(name) - 1;
    while (start < end)
    {
        if (name[start++] == name[end--])
        {
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char name[20];
    cout << "Enter your name: ";
    cin.getline(name,100);
    cout << "Your name is: " << name << endl;

    cout << getLength(name) << endl;

    reverseSetring(name);

    cout << "Is valid Palindrome or not: " << checkPalindrome(name);

    return 0;
}