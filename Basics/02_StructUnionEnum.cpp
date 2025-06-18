#include <iostream>
using namespace std;

typedef struct employee{  //By using typedef we can give strycture employee a nickname 'em'
    char name[20];
    int age;
    float salary;
}em;

enum Language {English= 4, Hindi, Hinglish};
enum{TRUE, FALSE};

int main()
{
    // cout<<"Enter employee name: ";
    // struct employee Devanshu;

    // cin.getline(Devanshu.name, 20);

    // Devanshu.age = 18;
    // Devanshu.salary = 4600000000;

    // cout<< Devanshu.name <<endl;
    // cout<< Devanshu.age <<endl;
    // cout<< Devanshu.salary <<endl;

    // //Using 'em' nickname
    // em Rohan; //We don't have to use struct now
    // Rohan.age = 50;
    // cout<<Rohan.age;


    // ******************************Enum******************************************

    cout<<TRUE; //TRUE is 0 now, by default it'll start from 0 
    cout<<Hinglish; //It'll print 06 as first value is 4 and 4 + 2 = 06

    return 0;
}