
#include <stdio.h>
#include <stdlib.h>


//self referencing structure with one data element
struct Node {
    int data;
    struct Node *next;
};


// Aliasing for easier referencing
typedef struct Node Node; 

/*-------------------------------------- Linked List Functions -------------------------------------- */
/** Ideally these should go in a seperate Header file (ie. linked_list.h) along with the self referencing structures 
 * 
 * Linked List Functions
 * Create Node  : create_node
 * Insert       : insert_head, insert_tail, insert_next_to
 * Update       : update
 * Search       : search
 * Delete       : delete
 * Display List : print_list
 * 
 */

// Creates a Node in Heap and returns a pointer
Node * create_node(int data){
    Node *node = malloc(1 * sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

// Searches for the given value and returns the node if found
Node * search(Node *head, int value) {

    while(head != NULL) {
        if(head->data == value) {
            return head;
        }

        head = head->next;
    }

    return NULL;
}


// appends a node to the end of the Linked List
void insert_tail(Node **head, int data) {
    if(*head == NULL) {
        *head = create_node(data);
    }else {
        Node *current = *head;

        while(current->next != NULL) {
            current = current->next;
        }

        current->next = create_node(data);
    }
}

// appends a node to the beginning of the Linked List
void insert_head(Node **head, int data) {
    Node *new_node = create_node(data);

    new_node->next = *head;
    *head =  new_node;
}

// appends the node next to the node with given value 
void insert_next_to(Node *head, int next_to, int data) {
    Node *search_result = search(head, next_to);

    if(search_result != NULL) {
        Node *new_node = create_node(data);

        new_node->next = search_result->next;
        search_result->next = new_node;
    }else {
        printf("Insert Failed : No such value found!!\n");
    }
}

// Updates specific element in the Linked List
void update(Node *head, int old_value, int new_value) {
    Node *search_result = search(head, old_value);

    if(search_result != NULL) {
        search_result->data = new_value;
    }else {
        printf("Update Failed : Value not found!!\n");
    }
}

// looks for (int value) and deletes the first node containing (int value) if found 
int delete(Node **head, int value) {
    if(*head == NULL) {
        printf("Delete Faied : Empty List\n");
        return -1;
    }

    Node *current = *head;
    Node *previous = NULL;

    while(current != NULL) {
        if(current->data == value) {
            break;
        }

        previous = current;
        current = current->next;
    }

    if(current == NULL) {
        printf("Delete Faied : Value not found!!\n");
        return -1;
    }else {
        if(current == *head) {
            *head = (*head)->next;
        }else {
            previous->next = current->next;
        }

        int deleted = current->data;

        free(current);

        printf("Successfully deleted %d\n", deleted);

        return deleted;
    }
}


// Prints all the elements in the linked list
void print_list(Node *head) {
    if(head == NULL) {
        printf("Empty List !!\n"); 
    }else {

        printf("[");

        while(head != NULL) {
            printf(" %d", head->data);
            
            if(head->next != NULL) printf(",");

            head = head->next;
        }

        printf(" ]\n");
    }
}

/* --------------------------------- End of Linked List Functions ----------------------------------- */

int main() {
    Node *head = NULL;      // Pointer to the First Node of the Linked List

    insert_tail(&head, 10);
    insert_tail(&head, 50);

    insert_head(&head, 5);

    insert_next_to(head, 10, 11);

    update(head, 10, 19);

    delete(&head, 19);

    print_list(head);

    return 0;
}