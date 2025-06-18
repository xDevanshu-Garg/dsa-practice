#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node * &head, int data){
    // Node* temp = new Node(data);
    // head = temp;

    head = new Node(data);
}

void insertAtTail(Node* &head, int data){
    Node* prev = head;
    while (prev->next != NULL)
    {
        prev = prev->next;
    }

    Node* temp2 = new Node(data);
    prev->next = temp2;
}

void insertAtIndex(Node* & head, int index, int data){
    //for head
    if (index == 0)
    {
        insertAtHead(head, data);
        return;
    }
    
    Node* prev = head;
    //stop before index
    for (int i = 1; i < index; i++)
    {
        //safety check if len < index
        if(prev->next == NULL){
            cout <<"Index out of bounds!" <<endl;
            return;
        }
        prev = prev->next;
    }
    Node* temp2 = new Node(data);
    temp2->next = prev->next;
    prev->next = temp2;
}

int getLength(Node* &head){
    int count = 0;
    Node* temp = head;
    while (temp != NULL )
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void deleteAtIndex(Node* &head, int index){
    //For head
    if (index == 0){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    
    Node* temp = head;
    for (int i = 1; i < index; i++)
    {
        if(temp->next == NULL){
            cout <<"Index out of bounds!" <<endl;
            return;
        }
        temp = temp->next;
    }
    //Final safety check because above loop only places our temp pointer to one node before index.
    if (temp->next == NULL)
    {
        cout<<"Index out of bounds!" <<endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL" <<endl;
}

int main()
{   
    //Creating a node
    Node *node1 = new Node(10);
    // cout<<node1->data <<endl;
    // cout<<node1->next <<endl;

    //making node1 head
    Node* head = node1; 
    print(head);

    // //inserting
    insertAtHead(head, 99);
    print(head);

    insertAtHead(head, 55);
    print(head);

    insertAtTail(head, 87);
    print(head);

    insertAtTail(head, 85);
    print(head);

    insertAtIndex(head, 2, 44);
    print(head);

    //inserting at head using index
    insertAtIndex(head, 0, 1);
    print(head);

    //inserting at last using index
    insertAtIndex(head, 7, 44);
    print(head);

    //Calling the safety check
    insertAtIndex(head, 10, 44);
    print(head);

    cout<<"Length of linked list is: " << getLength(head)<<endl;

    //Now Deleting nodes
    deleteAtIndex(head, 0);
    print(head);

    deleteAtIndex(head, 5);
    print(head);

    deleteAtIndex(head, 5);
    print(head);

    deleteAtIndex(head, 5);
    print(head);
    return 0;
}