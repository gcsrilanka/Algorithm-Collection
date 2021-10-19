#include <stdio.h>
#include <stdlib.h>

//self referencing structure with one data element
struct Node {
    int data;
    struct Node *next;
};

// Aliasing for easier referencing
typedef struct Node Node; 

/*-------------------------------------- Stack Functions -------------------------------------- */
/** Ideally these should go in a seperate Header file (ie. stack.h) along with the self referencing structure
 * 
 * Stack Functions
 * Create Node   : create_node
 * Push          : push (adds an item to the top of the stack)
 * Pop           : pop (removes the topmost item from the stack)
 * Peek          : peek (take a look at the topmost item without popping)
 * Display Stack : print_stack
 * 
 */

Node * create_node(int data) {
    Node *new_node = malloc(1 * sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}


// adds a Node to the top of the stack
void push(Node **top, int data) {
    Node *new_node = create_node(data);

    if(*top != NULL) {
        new_node->next = *top;
    }

    *top = new_node;

}

// Pops the Top Node from the Stack
int pop(Node **top) {
    if(*top == NULL) {
        printf("Popping Failed: Empty Stack !!\n");
        return -1;
    }

    Node *popped = *top;

    *top = popped->next;

    int popped_int = popped->data;
    
    free(popped);

    printf("Successfully Popped : %d\n", popped_int);

    return popped_int;
}

// Prints all the elements in the Stack
void print_stack(Node *top) {
    if(top == NULL) {
        printf("Empty Stack!!\n");
        return;
    }

    printf("[");

    while(top != NULL) {
        printf(" %d", top->data);

        if(top->next != NULL) printf(",");

        top = top->next;
    }

    printf(" ]\n");
}

//Prints the topmost item in the Stack 
void peek(Node *top) {
    if(top == NULL) {
        printf("Empty Stack!!\n");
    }else {
        printf("First item of the Stack : %d\n", top->data);
    }
}

/* --------------------------------- End of Stack Functions ----------------------------------- */

int main() {
    Node *stack = NULL;

    push(&stack,10);
    push(&stack,20);
    push(&stack,50);

    pop(&stack);
    peek(stack);
    

    push(&stack,40);
    push(&stack,80);

    print_stack(stack);

}