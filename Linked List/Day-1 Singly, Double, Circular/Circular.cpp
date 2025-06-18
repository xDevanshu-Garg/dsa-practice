#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if (this->next!=NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for node with data " << value << endl;
    }
};

void insertByValue(Node* &tail, int element, int data){
    //Empty
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{ //non-empty list
        Node* curr = tail;
        
        while (curr->data != element)
        {
            curr = curr->next;
        }
        //element found, curr is representing element node
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr ->next = temp;
    }
}

void deleteNode(Node* &tail, int element){
    //empty
    if(tail == NULL){
        cout<<"List is empty!" <<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* tail){
    Node* temp = tail;

    do
    {
        cout<<tail->data <<" -> ";
        tail = tail->next;
    } while (tail != temp);
    cout<<"NULL" <<endl;
    
}

int main()
{
    Node* tail = NULL;
    insertByValue(tail, 5, 30);
    print(tail);

    insertByValue(tail, 30, 36);
    print(tail);

    insertByValue(tail, 30, 33);
    print(tail);

    insertByValue(tail, 36, 39);
    print(tail);

    deleteNode(tail, 30);
    print(tail);

    return 0;
}