//! https://www.naukri.com/code360/problems/two-stacks_983634?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h> 
class TwoStack {

public:
        int *arr;
        int top1;
        int top2;
        int size;

    // Initialize TwoStack.
    TwoStack(int s) {
        size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if((top1 < size-1) && (top2-top1 > 1)){
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if((top2 > 0) && (top2-top1 > 1)){ //OR (top2-top1) > 1 means dono ke beech kam se kam ek array ka dabba to hona hi chaiye 1 means ek ka anter h to koi dabba beech me nhi hoga 5-4 = 1 yaha 4 pr bhi ek ele h aur 5 pr bhi so atleast 2 chaiye
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0) return arr[top1--];
        else return -1;

    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 <= size-1) return arr[top2++];
        else return -1;
    }
};