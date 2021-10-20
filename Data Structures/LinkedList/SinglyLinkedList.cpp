/*
First add number of nodes you need and then,
Insert Space Separated values when asked.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    Node *next;
    int data;
};

class LinkedList {
private:
    Node *start = NULL;
public:
    void insertBeg(int x);    // Insert a new node at the beginning
    void insertEnd(int x);    // Insert a node at the end
    void deleteBeg();        // Delete a node from the beginning
    void deleteEnd();        // Delete a node from the end
    void deleteNode(int D); // Delete a node with a given value
    void print();            // Print current list
    Node *search(int F);    // Search an existing element
    int sum();                // Add list values to get sum
};

//Insert New Node at the beginning
void LinkedList::insertBeg(int x) {
    Node *newNode = new Node;
    //If there is no data in the link list
    if (start == NULL) {
        start = newNode;
        newNode->data = x;
        newNode->next = NULL;
    } else {
        newNode->data = x;
        newNode->next = start;
        start = newNode;
    }
    cout << "Element Inserted to End" << endl;
}

void LinkedList::insertEnd(int x) {
    Node *newNode = new Node;
    //If there is no data in the link list
    if (start == NULL) {
        newNode->data = x;
        newNode->next = NULL;
        start = newNode;
    } else {
        newNode->data = x;
        newNode->next = NULL;
        Node *ptr = start;

        while (ptr->next != NULL) {    // Search for the last node
            ptr = ptr->next;
        }
        ptr->next = newNode;
        cout << "Node Inserted at the End";
    }
}

void LinkedList::deleteBeg() {
    //If there is no data in the link list
    if (start == NULL) {
        cout << "Link list is empty";
        return;
    }
    Node *ptr = start;
    start = start->next;
    free(ptr);
    cout << "Node delete from the beginning.";
}

void LinkedList::deleteEnd() {

    //If there is no data in the link list
    if (start == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }else if(start -> next == NULL)
    {
        start = NULL;
        free(start);
        printf("\nOnly node of the list deleted ...");
    }

    else
    {
        Node *ptr = start;
        Node *ptr1;

        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\n Deleted Node from the last ...");
    }
}


void LinkedList::deleteNode(int D) {
    Node *ptr = start;

    //If beginning value = D delete from beginning
    if (start->data == D) {
        deleteBeg();
    } else {
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
            if (ptr->data == D) {
                free(ptr);
                cout << "Node with value " << D << " Deleted.";
                return;
            }
        }
    }
    //If end value = D delete from end
    if (ptr->next->data == D) {
        deleteEnd();
    }
}

void LinkedList::print() {
    Node *ptr = start;
    //If there is no data in the link list
    if (start == NULL) {
        cout << "No data available " << endl;
        return;
    } else {
        while (ptr != NULL) {    //count the number of nodes
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}

Node *LinkedList::search(int F) {
    Node *ptr = start;
    while (ptr->next != NULL) {    // search for the element node by node
        if (ptr->data == F) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

int LinkedList::sum() {
    int sum = 0;
    Node *ptr = start;
    while (ptr != NULL) {    // add data node by node
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}


int main() {
    LinkedList linkedList;
    int num_nodes, values, input;

    //Get number of initial nodes
    cout << "Number of nodes : ";
    cin >> num_nodes;

    //Initializing the linklist
    for (int i = 0; i < num_nodes; i++) {
        cout << "Input data : ";    //get values
        cin >> values;
        linkedList.insertBeg(values);
    }

    cout << endl << endl;

    while (true) {
        cout << "1 - Insert Beginning\n"
                "2 - Insert End\n"
                "3 - Delete Beginning\n"
                "4 - Delete End\n"
                "5 - Delete Value\n"
                "6 - Print\n"
                "7 - Search\n"
                "8 - Sum\n"
                "0 - Exit\n\n";
        cout << "Enter your choice : ";
        cin >> input;
        cout << endl;
        switch (input) {
            case 1:
                cout << "Enter the value : ";
                cin >> values;
                linkedList.insertBeg(values);
                break;
            case 2:
                cout << "Enter the value : ";
                cin >> values;
                linkedList.insertEnd(values);
                break;
            case 3:
                linkedList.deleteBeg();
                break;
            case 4:
                linkedList.deleteEnd();
                break;
            case 5:
                cout << "\nEnter the value of the node to be delete : ";
                cin >> values;
                linkedList.deleteNode(values);
                break;
            case 6:
                cout << "Link list : ";
                linkedList.print();
                break;
            case 7:
                cout << "Enter value to be searched : ";
                cin >> values;
                // Search an existing element
                if (linkedList.search(values) != NULL)
                    cout << "\nElement Found " << endl;
                else
                    cout << "\nElement Not Found" << endl;
                break;
            case 8:
                cout << "The sum of the link list : ";
                cout << linkedList.sum();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid Input.";
        }
        cout << endl << endl;
        cout << "Current link list : \t\n";
        linkedList.print();
        cout << endl << endl;
        system("pause");
        cout << endl << endl;
    }
    return 0;
}
