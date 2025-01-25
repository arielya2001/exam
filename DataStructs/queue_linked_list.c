#include <stdlib.h>

//WE USE THIS APPROACH, WHEN WE DON'T KNOW THE SIZE OF THE QUEUE!!!//




// Define the node struct for individual elements
typedef struct NODE_ {
    int data;
    struct NODE_ *next;
} node, *pnode;

// Define the queue struct with head and tail pointers
typedef struct QUEUE_ {
    pnode head; // Points to the first element
    pnode tail; // Points to the last element
} queue, *pqueue;

// Function to initialize the queue
pqueue createQueue() {
    pqueue q = (pqueue)malloc(sizeof(queue));
    if (!q) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    q->head = NULL;
    q->tail = NULL;
    return q;
}

// Function to add an element to the queue
void push(pqueue q, int num) {
    pnode n = (pnode)malloc(sizeof(node));
    if (!n) {
        printf("Memory allocation failed\n");
        return;
    }
    n->data = num;
    n->next = NULL;
    
    // If the queue is empty
    if (!q->head) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n; // Link the new node at the end
        q->tail = n;       // Update the tail pointer
    }
    printf("Pushed %d into the queue\n", num);
}

// Function to remove an element from the queue
int pop(pqueue q) {
    if (!q->head) {
        printf("Queue is empty, cannot pop\n");
        return -1;
    }
    int data = q->head->data;
    pnode temp = q->head;
    q->head = q->head->next; // Move the head pointer to the next node
    free(temp);              // Free the memory of the old head
    if (!q->head) {          // If the queue becomes empty
        q->tail = NULL;
    }
    return data;
}

int main() {
    pqueue q = createQueue();
    if (!q) return 1;

    push(q, 10);
    push(q, 20);
    push(q, 30);

    printf("Popped: %d\n", pop(q));
    printf("Popped: %d\n", pop(q));
    printf("Popped: %d\n", pop(q));
    printf("Popped: %d\n", pop(q)); // Should indicate the queue is empty

    free(q); // Clean up the queue structure
    return 0;
}