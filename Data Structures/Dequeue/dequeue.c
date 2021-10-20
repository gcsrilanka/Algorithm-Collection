#include <stdio.h>
#include <stdlib.h>

//self referencing structure with one data element
struct node{
    int data;
    struct node *next, *perv;
};

// Aliasing for easier referencing
typedef struct node node;

/*-------------------------------------- Dequeue Functions -------------------------------------- */
/** Ideally these should go in a seperate Header file (ie. dequeue.h) along with the self referencing structure
 * 
 * Note : Dequeue is a ADT which is also a derived DS from LinkedList
 * 
 * Dequeue Functions
 * Create Node       : create
 * Insert to front   : insertFront (append to the front of Dequeue)
 * Insert to end     : insertRear (append to the end of Dequeue)
 * Delete from front : deleteFront (remove the first node of the Dequeue)
 * Delete from end   : deleteRear (remove the last node of the Dequeue)
 * Peek from front   : peekFront(views the first element in the Dequeue)
 * Peek from end     : peekFront(views the last element in the Dequeue)
 * check emptiness   : IsEmpty(if it is empty, then return 1)
 * Display List      : display
 * 
 */

// create a dequeue 
typedef struct deqeue{
    int count;
    node* front;
    node* rear;
}deqeue;

// Creates a Node in Heap and returns a pointer

void create(deqeue* dq){
    dq->count = 0;
    dq->front = NULL;
    dq->rear = NULL;
}

// check emptiness
int IsEmpty(deqeue* dq){
    if(dq->front==NULL && dq->rear==NULL)
        return 1;
    else
        return 0;
}

// appends a node to the front of the Dequeue
void insertFront(deqeue* dq, int data){
    node* np = (node*)malloc(sizeof(node));
    if(np==NULL)
        printf("memory is not enoungh...\n");
    else{
        dq->count++;
        np->data = data;
        np->perv = NULL;
        if(IsEmpty(dq)){
            np->next = NULL;
            dq->front = np;
            dq->rear = np;
        }
        else{
            np->next = dq->front;
            dq->front->perv = np;
            dq->front = np;
        }
    }
}

// appends a node to the end of the Dequeue
void insertRear(deqeue* dq, int data){
    node* np = (node*)malloc(sizeof(node));
    if(np==NULL)
        printf("memory is not enoungh...\n");
    else{
        dq->count++;
        np->data = data;
        np->next = NULL;
        if(IsEmpty(dq)){
            np->perv = NULL;
            dq->front = np;
            dq->rear = np;
        }
        else{
            np->perv = dq->rear;
            dq->rear->next = np;
            dq->rear = np;
        }
    }
}

// removes the first element in the dequeue
void deleteFront(deqeue* dq){
    if(IsEmpty(dq))
        printf("deqeue is empty...\n");
    else{
        node* temp = dq->front;          // address of node that to be deleted
        dq->front = dq->front->next;
        if(dq->front==NULL)              // if deque has one element
            dq->rear=NULL;
        else{
            dq->front->perv = NULL;
        }
        free(temp);
    }
}

// removes the last element in the dequeue
void deleteRear(deqeue* dq){
    if(IsEmpty(dq))
        printf("deqeue is empty...\n");
    else{
        node* temp = dq->rear;
        dq->rear = dq->rear->perv;
        if(dq->rear==NULL)
            dq->front=NULL;
        else{
            dq->rear->next = NULL;
        }
        free(temp);
    }
}

//Takes a peek at the first element in the dequeue
void peekFront(deqeue* dq){
    if(IsEmpty(dq))
        printf("deqeue is empty...\n");
    else{
      printf("first element is %d\n", dq->front->data);
    }
}

//Takes a peek at the last element in the dequeue
void peekRear(deqeue* dq){
  if(IsEmpty(dq))
    printf("deqeue is empty");
  else{
    printf("last eleement is %d\n", dq->rear->data);
  }
}

// Prints all the elements in the Dequeue
void display(deqeue* dq){
    if(IsEmpty(dq))
        printf("deqeue is empty...\n");
    else{
        node* temp = dq->front;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* --------------------------------- End of Dequeue Functions ----------------------------------- */


int main(){
  deqeue dq;                 // create deqeue
  create(&dq);
  insertFront(&dq, 1);
  insertFront(&dq, 2);
  display(&dq);
  peekFront(&dq);
  insertRear(&dq, 44);
  peekRear(&dq);
  display(&dq);
  deleteRear(&dq);
  display(&dq);


  return 0;
}