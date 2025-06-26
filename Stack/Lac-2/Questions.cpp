#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//!Delete Middle Element in Stack:https://bit.ly/3ovTIu2

void solve(stack<int>&inputStack, int N, int count){
   //Base Case
   if(count == N/2){
      inputStack.pop();
      return;
   }
   //Processing
   int num = inputStack.top();
   inputStack.pop();

   //RR
   solve(inputStack, N, ++count);
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;

   solve(inputStack, N, count);
}

//! Valid Parenthesis:https://bit.ly/34kxPaq

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if(st.empty()) st.push(ch);
            else if ((st.top() == '(' && ch == ')') ||
                (st.top() == '{' && ch == '}') ||
                (st.top() == '[' && ch == ']')) {
                st.pop();
            }
            else st.push(ch);
        }
        return st.empty();
    }
};


//! InsertAtBottom in Stack:https://bit.ly/34qqmGL

#include <bits/stdc++.h> 

void solve(stack<int>&stack, int x){
   //Base Case
   if(stack.empty()){
      stack.push(x);
      return;
   }
   //Processing
   int num = stack.top();
   stack.pop();

   //RR
   solve(stack, x);
   stack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
   solve(myStack, x);
   return myStack;
}


//! Reverse a Stack using recursion:https://bit.ly/3HCBnD4

void insertAtBottom(stack<int>&stack, int x){
   //Base Case
   if(stack.empty()){
      stack.push(x);
      return;
   }
   //Processing
   int num = stack.top();
   stack.pop();

   //RR
   insertAtBottom(stack, x);
   stack.push(num);
}

void reverse(stack<int> &s){
   //  Base Case
    if(s.empty()){
        return;
    }

    int val = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, val);
}

void reverseStack(stack<int> &stack) {
    reverse(stack);
}

//! Reverse a stack using another stack

void reverseStack(stack<int>& s) {
    stack<int> temp;

    // Transfer all elements to temp stack
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    // Transfer back to original stack
    s = temp;
}
//! Redundant Brackets:https://bit.ly/3srTkOv

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for(int i = 0; i<s.length(); i++){
        char ch = s[i];
        if((ch == '(') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
            st.push(ch);
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if((top == '+') || (top == '-') || (top == '*') || (top == '/')){
                        isRedundant = false;
                    }
                    st.pop();
                }
                st.pop();
                if(isRedundant == true) return true;
            }
        }
    }
    return false;
}

//! Minimum bracket Reversal:https://bit.ly/3GAYRr5

int findMinimumCost(string str) {
  // If string is odd then solution is not possible
  if((str.length() % 2) != 0) return -1; 
  else{
      //Step2: remove valid brackets so that only the brackets with issue remains.
      stack<char> st;
      for (char ch : str) {
        if(st.empty()) st.push(ch);
        else if (st.top() == '{' && ch == '}') {
          st.pop();
        }else
          st.push(ch);
      }
      if(st.empty()) return 0;

      //Let's count no. of '{' and '}' in terms of a and b
      int a = 0, b = 0;
      while(!st.empty()){
        if(st.top() == '{') a++;
        else b++;
        st.pop();
      }
      return ((a+1)/2 + (b+1)/2);
  }
}