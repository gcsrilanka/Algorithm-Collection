#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 100

class Stack {
    int top;
public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    // Overflow Condition
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}

int Stack::pop() {
    // Underflow Conditions
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

// Driver program to test above functions
int main() {
    class Stack stk;

    // Adding Item to Stack
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout<< "1, 2, 3 added to stack\n";

    // Pop up Stack
    cout << stk.pop() << " Popped from stack\n";

    // Get the top values
    cout << stk.peek() << " is the peek value\n";

    // isEmpty
    if (stk.isEmpty() < 0){
        cout<< "Empty\n";
    }
    else {
        cout << "Not empty\n";
    }
    return 0;
}
