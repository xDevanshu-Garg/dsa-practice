#include <iostream>
using namespace std;

class Hero{
    public:
    int level;
    int health;

    void print(){
        cout<<"Health: " <<health <<endl;
        cout<<"Level: " <<level <<endl;
    }

    //Default constructor
    Hero(): level(0),health(0){}

    //Parameterized constructor
    Hero(int l, int h): level(l),health(h){}

    //copy constructor 
    Hero(Hero& temp){
        this->level = temp.level;
        this->health = temp.health;
    }

};


int main()
{
    //Dynamic way of creating object
    Hero *b = new Hero; 

    //we can use dereferencing operator or arrow operator
    cout<<"Health: " <<(*b).health <<endl;
    cout<<"Level: " <<b->level<<endl;

    Hero ramesh(12, 100);
    ramesh.print();

    //calling copy constructor
    Hero a(ramesh);
    a.print();
    
    return 0;
}