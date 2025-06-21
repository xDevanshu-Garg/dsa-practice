//! Special Stack: https://bit.ly/3LpVPJM -Coding ninjas
/*
// Brute force will be two maintain a second stack for minimum values
// ************************optimised approch***********************
// by modifying the values pushed into the stack when a new minimum is encountered, so that we can retrieve the previous minimum without using an auxiliary stack.
class SpecialStack {
    public:
        int mini = INT_MAX;
        stack<int>s;
        
    void push(int data) {
        // For first element normal push
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            //else push but check if we have new minimum and apply formula
            if(data < mini){
                int newData = 2 * data - mini;
                s.push(newData);
                mini = data;
            }
            else{ //normal push if we don't have new minimum
                s.push(data);    
            }
        }
    }

    void pop() {
        // Underflow condition
        if(s.empty()) return;
        // if curr element is greater then minimum then no problem
        if(s.top() >= mini){
            s.pop();
        }
        //else update mini in the case where top is less then mini
        else{
            mini = 2 * mini - s.top();
            s.pop();
        }
    }

    int top() {

        // if top is greater then minimum no problem
        if(s.top() >= mini){
            return s.top();
        }
        else{
            return mini;
        }
    }

    int getMin() {
        return mini;
    }  
};
*/

//! Leetcode version
/*
// Brute force will be two maintain a second stack for minimum values
// ************************optimised approch***********************
// by modifying the values pushed into the stack when a new minimum is encountered, so that we can retrieve the previous minimum without using an auxiliary stack.
class MinStack {
public:

    long long mini = INT_MAX;
    stack<long long>s;

    MinStack() {
    }
    
    void push(int val) {
        // For first element normal push
        if(s.empty()){
            s.push(val);
            mini = val;
        }
        else{
            //else push but check if we have new minimum and apply formula
            if(val < mini){
                long long valLL = val;
                long long newval = 2 * valLL - mini;
                s.push(newval);
                mini = val;
            }
            else //normal push if we don't have new minimum
                s.push(val);    
        }
    }
    
    void pop() {
        // if curr element is greater then minimum then no problem
        if(s.top() >= mini){
            s.pop();
        }
        //else update mini in the case where top is less then mini
        else{
            mini = 2 * mini - s.top();
            s.pop();
        }
    }
    
    int top() {
        // if top is greater then minimum no problem
        if(s.top() >= mini)
            return s.top();
        else
            return mini;
    }
    
    int getMin() {
        return mini;
    }
};

// Brute force will be two maintain a second stack for minimum values
// ************************optimised approch***********************
// by modifying the values pushed into the stack when a new minimum is encountered, so that we can retrieve the previous minimum without using an auxiliary stack.
class MinStack {
public:

    long long mini = INT_MAX;
    stack<long long>s;

    MinStack() {
    }
    
    void push(int val) {
        // For first element normal push
        if(s.empty()){
            s.push(val);
            mini = val;
        }
        else{
            //else push but check if we have new minimum and apply formula
            if(val < mini){
                long long valLL = val;
                long long newval = 2 * valLL - mini;
                s.push(newval);
                mini = val;
            }
            else //normal push if we don't have new minimum
                s.push(val);    
        }
    }
    
    void pop() {
        // if curr element is greater then minimum then no problem
        if(s.top() >= mini){
            s.pop();
        }
        //else update mini in the case where top is less then mini
        else{
            mini = 2 * mini - s.top();
            s.pop();
        }
    }
    
    int top() {
        // if top is greater then minimum no problem
        if(s.top() >= mini)
            return s.top();
        else
            return mini;
    }
    
    int getMin() {
        return mini;
    }
};

*/