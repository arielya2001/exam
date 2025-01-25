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

typedef struct {
    int *items;
    int front;
    int rear;
    int max_size;
    int current_size;
}Queue;

void create(Queue* my_fifo, int size){
    my_fifo->items = (int*)malloc(size*sizeof(int));
    if(!my_fifo->items){
        printf("malloc failed!");
        return;
    }
    my_fifo->front = 0;
    my_fifo->current_size = 0;
    my_fifo->max_size = size;
    my_fifo->rear = -1;
}

void enqueue(Queue* my_fifo, int data){
    if(my_fifo->current_size == my_fifo->max_size){
        printf("queue is full!");
        return;
    }
    my_fifo->rear = (my_fifo->rear+1)%(my_fifo->max_size);
    my_fifo->items[my_fifo->rear] = data;
    my_fifo->current_size++;
}
void dequeue(Queue* my_fifo){
    if(my_fifo->current_size==0){
        printf("queue empty");
        return;
    }
    my_fifo->front = (my_fifo->front+1)%(my_fifo->max_size);    
    my_fifo->current_size--;
}














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






