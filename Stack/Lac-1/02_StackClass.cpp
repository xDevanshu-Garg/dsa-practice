// Using Arrays

#include <iostream>
using namespace std;

class Stack{

    public:
    //Properties
    int *arr;
    int top;
    int size;

    //Behaviours
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele){
        if(top < size - 1){
            top++;
            arr[top] = ele;
        }
        else cout<<"Stack Overflow!" <<endl;
    }

    int pop(){
        if(top >= 0) return arr[top--];

        cout<<"Stack Underflow!" <<endl;
        return -1;
    }

    int peek(){
        if(empty()) {
            cout<<"Stack is Empty"; 
            return -1;
        }
        else return arr[top];
    }

    bool empty(){
        return top == -1;
    }

    ~Stack(){
        cout << "Destructor called. Memory is freed." << endl;
        delete[] arr;
    }

};

int main()
{
    Stack s(5);
    s.push(22);
    s.push(43);
    s.push(44);

    s.pop();
    cout << s.peek() <<endl;

    s.pop();
    cout << s.peek() <<endl;   

    s.empty() ? cout<<"Stack is Empty\n" : cout<<"Stack is not Empty\n";

    s.push(22);
    s.push(43);
    s.push(44);
    s.push(22);
    s.push(43);
    s.push(44);
    cout << s.peek() << endl;


    return 0;
}