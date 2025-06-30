/*
top <- new node <- new node <- new node
        new top    new top     new top

*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Stack{
    public:
    //Properties
    Node* top;

    Stack(){
        top = NULL; 
    }

    void push(int val){
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
    }

    int pop(){
        if(empty()){
        cout << "Stack Underflow!" << endl;
        return -1;
    }
        Node* temp = top;
        int val = top->data;
        top = top->next;
        delete temp;
        return val;
    }

    int peek(){
        if(empty()){
            cout<<"Stack is Empty" << endl; 
            return -1;
        }
        return top->data;
    }

    bool empty(){
        return top == nullptr;
    }

    void display(){
        Node* temp = top;
        while(temp != nullptr){
            cout<<temp->data << " -> "; 
            temp = temp->next;
        }
        cout<<"NULL";
    }

    ~Stack(){
        while (top != nullptr)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    } 
};


int main()
{
    Stack s;

    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);

    s.pop();
    cout<<"Is LL empty? " << s.empty() << endl;
    cout<<"Top of LL is: " << s.peek() << endl;

    s.display();

    return 0;
}