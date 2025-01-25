#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100
#define C1_MASK 62   //mask is a binary number where the desired bits here 1-5 c1
#define C2_MASK 384  //are set to 1, and all other bits are set to 0
#define O1_MASK 1024 // 2^10
#define O2_MASK 4096 //2^12

void operations(unsigned status){

int status;
int c1 = (status & C1_MASK) >> 1;
int c2 = (status & C2_MASK) >> 7;//status & 7,8 bits on = extract bits 7,8 from status!
int o1 = (status & O1_MASK) >> 10;//always shift right until we reach LSB
int o2 = (status & O2_MASK) >> 12;//now, when we perfom int, we get the value!

if (o1 && o2)
	printf("%d\n", c1 / c2);
if (o1 && !o2)
	printf("%d\n", c1 * c2);
if (!o1 && !o2)
	printf("%d\n", c1 + c2);
if (!o1 && o2)
	printf("%d\n", c1 - c2);
}
#include <stdio.h>

typedef struct {
    unsigned int c1 : 5; // 5 bits for c1
    unsigned int c2 : 2; // 2 bits for c2
    unsigned int o1 : 1; // 1 bit for o1
    unsigned int o2 : 1; // 1 bit for o2
} status_struct;



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
    // // Initialize the structure
    // status_struct status = { .c1 = 10, .c2 = 3, .o1 = 1, .o2 = 0 };

    // // Perform operations based on o1 and o2
    // if (status.o1 && status.o2)
    //     printf("%d\n", status.c1 / status.c2); // Division
    // if (status.o1 && !status.o2)
    //     printf("%d\n", status.c1 * status.c2); // Multiplication
    // if (!status.o1 && !status.o2)
    //     printf("%d\n", status.c1 + status.c2); // Addition
    // if (!status.o1 && status.o2)
    //     printf("%d\n", status.c1 - status.c2); // Subtraction
    // double num1, num2;
    // scanf("%lf %lf", &num1, &num2);
    // int mask = 1 << (8*sizeof(double) - 1);
    // for (int i=0; i < 8*sizeof(double); ++i)
    // {
    //     int digit1 = num1 & mask;	
    //     int digit2 = num2 & mask;
    //     if ((digit1 && !digit2) || (!digit1 && digit2))
    //         printf("1");
    //     else
    //         printf("0");
    //     num1 <<= 1;
    //     num2 <<= 1;
    // }
    return 0;
}

