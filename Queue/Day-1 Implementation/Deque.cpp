//! ***************************************Using STL ****************************************************************
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;

    // Insertion
    d.push_front(12);   // [12]
    d.push_back(14);    // [12, 14]

    // Accessing front and back
    cout << "Front: " << d.front() << endl;  // 12
    cout << "Back: " << d.back() << endl;    // 14

    // Deletion
    d.pop_front();      // [14]
    cout << "After pop_front:\n";
    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;

    d.pop_back();       // []

    // Empty check
    if (d.empty()) {
        cout << "Deque is empty" << endl;
    } else {
        cout << "Deque is not empty" << endl;
    }

    // More insertions
    d.push_back(1);     // [1]
    d.push_back(2);     // [1, 2]
    d.push_back(3);     // [1, 2, 3]
    d.push_front(0);    // [0, 1, 2, 3]

    // Size of deque
    cout << "Size: " << d.size() << endl;  // 4

    // Iterating over deque
    cout << "Elements: ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;

    // Clear all elements
    d.clear();
    cout << "Size after clear(): " << d.size() << endl;  // 0

    return 0;
}


//! ***************************************MANUAL IMPLEMENTATION***********************************************
//? Leetcode Link: https://leetcode.com/problems/design-circular-deque/

class MyCircularDeque {
public:
    int front,rear;
    int *arr , n;
    MyCircularDeque(int k) {
        arr = new int[k];
        front = rear = -1;
        n = k;
    }
    
    bool insertFront(int value) {
        //overflow
        if(isFull()) return false;
        // Single ele
        if(front == -1) front = rear = 0;
        //normal
        else front = (front - 1 + n) % n; //+n to avoid negative indices
        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        //overflow
        if(isFull()) return false;
        // Single ele
        if(front == -1) front = rear = 0;
        //normal
        else rear = (rear + 1) % n;
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        //Underflow
        if(isEmpty()) return false;
        //only one ele is left
        if(front == rear) front = rear = -1;
        else front = (front + 1) % n;
        return true;
    }
    
    bool deleteLast() {
        //Underflow
        if(isEmpty()) return false;
        //only one ele is left
        if(front == rear) front = rear = -1;
        else rear = (rear - 1 + n) % n;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % n == front;
    }
};