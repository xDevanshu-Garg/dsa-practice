#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

void insertAtIndex(Node* &head, int index, int data)
{
    //head
    if (index == 0){
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }

    Node* prevNode = head;
    for (int i = 1; i < index; i++)
    {
        if (prevNode == NULL) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        prevNode = prevNode->next;
    }
    Node* temp = new Node(data);

    // Linking temp node with next node
    temp->next = prevNode->next;
    if (prevNode->next != NULL) prevNode->next->prev = temp;

    // linking prev node with temp
    prevNode->next = temp;
    temp->prev = prevNode;
}

void deleteAtIndex(Node* &head, int index){
    //For head
    if (index == 0){
        Node* toDelete = head;
        head = head->next;
        head->prev = NULL;
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
    if(toDelete->next!=NULL) toDelete->next->prev = temp;
    delete toDelete;
}

void print(Node* head){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL" <<endl;
}

int main()
{
    Node* head = new Node(50);
    print(head);

    //inserting at head
    insertAtIndex(head, 0 , 55);
    print(head);

    //Inserting at tail
    insertAtIndex(head, 2 , 99);
    print(head);

    //Inserting in bw
    insertAtIndex(head, 1 , 3);
    print(head);

    //deleting
    deleteAtIndex(head, 1);
    print(head);

    deleteAtIndex(head, 0);
    print(head);

    deleteAtIndex(head, 1);
    print(head);

    return 0;
}