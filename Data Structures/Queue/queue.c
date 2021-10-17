#include <stdio.h>
#include <stdlib.h>

//self referencing structure with one data element
struct Node {
    int data;
    struct Node *next;
};

// Aliasing for easier referencing
typedef struct Node Node; 

/*-------------------------------------- Queue Functions -------------------------------------- */
/** Ideally these should go in a seperate Header file (ie. queue.h) along with the self referencing structure
 * 
 * Note : Queue is a ADT which is also a derived DS of LinkedList
 * 
 * Queue Functions
 * Create Node  : create_node
 * Insert       : enqueue (append to the end of Queue)
 * Delete       : dequeue (remove the first node of the Queue)
 * Peek         : peek (views the first element in the queue)
 * Display List : print_queue
 * 
 */

// Creates a Node in Heap and returns a pointer
Node * create_node(int data) {
    Node *new_node = malloc(1 * sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// appends a node to the end of the Queue
void enqueue(Node **front, int data) {
    if(*front == NULL) {
        *front = create_node(data);
    }else {
        Node *current = *front;

        while(current->next != NULL) {
            current = current->next;
        }

        current->next = create_node(data);
    }
}

// removes the first element in the queue
void dequeue(Node **front) {        // Can be modified to return the removed Node | int according to the usage
    if(*front == NULL) {
        printf("Dequeue Failed : Empty Queue!!\n");
        return;
    }

    Node *current = *front;

    *front = current->next;

    int deleted = current->data;

    free(current);

    printf("Dequeued : %d\n", deleted);

}

//Takes a peek at the first elemen in the queue
void peek(Node *head) {
    if(head == NULL) {
        printf("Empty Queue!!\n");
    }else {
        printf("First Element of the Queue : %d\n", head->data);
    }
}

// Prints all the elements in the Queue
void print_queue(Node *head) {
    if(head == NULL) {
        printf("Empty Queue!!\n");
        return;
    }
    
    printf("[");

    while(head != NULL) {
        printf(" %d", head->data);

        if(head->next != NULL) printf(",");

        head = head->next;
    }

    printf(" ]\n");
}
/* --------------------------------- End of Linked List Functions ----------------------------------- */

int main() {
    Node *queue = NULL;         // Pointer to the First Node of the Queue

    enqueue(&queue, 10);
    enqueue(&queue, 30);
    enqueue(&queue, 50);
    enqueue(&queue, 60);

    print_queue(queue);


    dequeue(&queue);
    dequeue(&queue);
    peek(queue);

    print_queue(queue);

    return 0;
}