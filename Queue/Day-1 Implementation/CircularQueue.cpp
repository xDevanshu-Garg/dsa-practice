//! 622. Design Circular Queue: https://leetcode.com/problems/design-circular-queue/?envType=problem-list-v2&envId=queue
/*
class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int n;
    MyCircularQueue(int k) {
        arr = new int[k];
        front = rear = -1;
        n = k;
    }
    
    bool enQueue(int value) {
        // overflow If that next slot is equal to front, it means: "We’re about to overwrite the front, so the queue is full."
        if((rear + 1) % n == front) return false;
        //First ele so adjustment is required
        if(front == -1) front = rear = 0;

        else rear = (rear + 1) % n;

        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        //underflow
        if(front == -1) return false;

        //only one ele left
        if(front == rear) front = rear = -1;
        //normal
        else front = (front+1) % n;

        return true;
    }
    
    int Front() {
        if(front == -1) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(front == -1) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % n == front;
    }
};

*/