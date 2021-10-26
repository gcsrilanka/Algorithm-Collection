#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StackNode {
public:
    int data;
    StackNode *next;
};

StackNode *root = NULL;

StackNode* newNode(int data){
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty() {
    return !root;
}

void push(int data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = root;
    root = stackNode;
}

int pop() {
    if (isEmpty())
        return INT_MIN;
    StackNode* temp = root;
    root = (root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek() {
    if (isEmpty())
        return INT_MIN;
    return root->data;
}

// Driver code
int main() {
    // Adding Item to Stack
    push(1);
    push(2);
    push(3);
    cout<< "1, 2, 3 added to stack\n";

    // Pop up Stack
    cout << pop() << " popped from stack\n";


    // Get the top values
    cout << "Top element is " << peek() << endl;

    // Print Stack by getting peek and then popping that item
    cout<<"Print Stack : ";
    while(!isEmpty()) {
        cout<<peek()<<" ";
        pop();
    }

    return 0;
}