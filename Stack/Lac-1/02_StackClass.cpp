// Using Arrays

/*
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
        if(top == -1) {
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
*/

// Using LL
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

    //Behaviours
    Stack(){
        top = NULL; 
    }

    void push(int val){
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
    }

    int pop(){
        if(top == nullptr){
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
        if(top == nullptr){
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