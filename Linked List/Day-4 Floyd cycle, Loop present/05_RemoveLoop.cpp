#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Deleting node with data " << this->data << endl;
    }
};

// Function to append at the end
void append(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to print list (will break if there's a loop!)
void printList(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < 20) { // avoid infinite loop if a cycle exists
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    if (count == 20) cout << "LOOP DETECTED (printing stopped)";
    else cout << "NULL";
    cout << endl;
}

// Optional: Floyd's Cycle Detection
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}

Node* StartingNodeOfLoop(Node * tail){
    if (tail == NULL)
        return NULL;

    Node* slow = tail;
    Node* fast = tail;

    while (fast != NULL)
    {
        slow = slow->next;

        fast = fast->next;
        if (fast != NULL) fast = fast->next;
        
        //if fast and slow overlapped then there is a cycle otherwise fast would have just reached end and slow and fast would have never met.
        if(fast == slow) {
            cout << "Loop at " << fast->data << " node"<<endl;
            slow = tail;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            cout << "starting node of loop at " << fast->data << endl;
            return slow;
        };
    }
    return NULL;
}

void removeLoop(Node* tail){
    
    Node* startOfTheLoop = StartingNodeOfLoop(tail);
    Node* temp = startOfTheLoop;
    while (temp->next != startOfTheLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node* loopStart = NULL;

    // Create list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    for (int i = 1; i <= 8; ++i) {
        append(head, tail, i);
        if (i == 4) loopStart = tail; // store node 4 to make a loop later
    }

    // Create loop: 8 -> 4
    tail->next = loopStart;

    // Try to print list (limited to 20 nodes to avoid infinite loop)
    printList(head);

    // Detect loop
    if (detectLoop(head)) {
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop." << endl;
    }

    removeLoop(head);
    printList(head);

    return 0;
}
