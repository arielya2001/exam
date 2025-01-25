#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

char* input() {  
    int count = 0; 
    char c; 
    char* str = (char*)malloc((count+1)*sizeof(char)); 
    char* cpy = str; 
    while(scanf("%c",&c) && c != '\n'){ 
        count++; 
        str = realloc(str, (count+1)*sizeof(char)); 
        if(!str){ 
            printf("Too long input"); 
            free(cpy); 
            return NULL; 
        } 
        cpy = str; 
        str[count-1] = c; 
    } 
    str[count] = '\0'; 
    return str;    
}

// typedef struct Node {
//     void* data;          // Pointer to hold any type of data
//     struct Node* next;   // Pointer to the next node in the queue
// } Node;

// typedef struct {
//     Node* front;         // Pointer to the front of the queue
//     Node* rear;          // Pointer to the rear of the queue
//     int size;            // Number of elements in the queue
//     int current_size;
// } Queue;



// void create_queue(int size, Queue *queue){
//     queue->size = size;
//     queue->front = NULL;
//     queue->rear = NULL;
//     queue->current_size = 0;
// }

// // Function to add an element to the queue
// void enqueue(Queue* queue, void* data) {
//     if (queue->current_size == queue->size) {
//         printf("Queue is full! Cannot enqueue.\n");
//         return;
//     }

//     Node* new_node = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
//     if (!new_node) {
//         printf("Memory allocation failed.\n");
//         return;
//     }

//     new_node->data = data;  // Assign the data
//     new_node->next = NULL;  // New node points to NULL

//     if (queue->rear) {
//         queue->rear->next = new_node; // Attach the new node to the rear
//     } else {
//         queue->front = new_node;      // If the queue is empty, front points to the new node
//     }

//     queue->rear = new_node;  // Update the rear pointer
//     queue->current_size++;   // Increment the size of the queue
// }

// // Function to remove an element from the queue
// void* dequeue(Queue* queue) {
//     if (queue->front == NULL) {
//         printf("Queue is empty! Cannot dequeue.\n");
//         return NULL;
//     }

//     Node* temp = queue->front;        // Get the front node
//     void* data = temp->data;          // Retrieve the data from the front node
//     queue->front = queue->front->next; // Move the front pointer to the next node

//     if (!queue->front) {              // If the queue becomes empty
//         queue->rear = NULL;           // Update the rear pointer to NULL
//     }

//     free(temp);                       // Free the memory of the dequeued node
//     queue->current_size--;            // Decrement the size of the queue

//     return data;                      // Return the dequeued data
// }

// // Function to free all memory used by the queue
// void free_queue(Queue* queue) {
//     while (queue->front != NULL) {
//         dequeue(queue); // Repeatedly dequeue and free memory
//     }
//     printf("Queue has been cleared.\n");
// }



void cmp_files(FILE *f1, FILE *f2){
    FILE *f3 = fopen("union.txt","w");
    if(!f3){
        printf("ERROR");
        return;
    }
    char *str1;
    char *str2;
    int read1 = fscanf(f1, "%s", str1);
    int read2 = fscanf(f2, "%s", str2);
    while(read1!=EOF && read2!=EOF){
        if(strcmp(str1,str2)){
            fprintf(f3,"%s",str1);
        }
        else{
            fprintf(f3,"%s",str1);
            fprintf(f3,"%s",str2);            
        }
    fscanf(f1,"%s",str1);
    fscanf(f2,"%s",str2);
    }
    while (read1 != EOF) {
        fprintf(f3, "%s ", str1);
        read1 = fscanf(f1, "%s", str1);
    }
    while (read2 != EOF) {
        fprintf(f3, "%s ", str2);
        read2 = fscanf(f2, "%s", str2);
    }
    fclose(f3);
}

void big_n_small(){
    char *str;
    printf("enter str: \n");
    scanf("%s",str);
    int small=0;
    int big = 0;
    int index = 0;
    while(str[index]!="\0"){
        if(str[index]>='a' && str[index]<='z'){
            small++;
        }
        else{
            big++;
        }
        index++;
    }
    printf("small and big %d%d",small,big);
}

typedef struct Node{
    int data;
    Node* next;
}Node;

Node* create_node(int num){
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node){
        printf("malloc failed!");
        return NULL;
    }
    node->data = num;
    node->next = NULL;
    return node;
}

void add_node(int num, Node* head){
    Node* node = create_node(num);
    if (!node){
        printf("malloc failed!");
        return;
    }
    Node* temp = head;
    if (!head || head->data >= num) {
        node->next = head;
        head = node; 
        return;
    }
    while(temp->next && temp->next->data<num){
        temp = temp->next;
    }
    node->next = temp ->next;
    temp->next = node;
}

void print_big(Node* head, int num){
    Node* temp = head;
    while(temp){
        if(temp->data >= num){
            printf("%d",temp->data);
        }
        temp = temp->next;
    }
}

void reverse(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;

    while (current) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move the `prev` pointer forward
        current = next;       // Move to the next node
    }

    *head_ref = prev; // Update the head pointer
}


void free_list(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp); // Free the current node
    }
}






