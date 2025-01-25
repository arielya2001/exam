#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
#define rows 2
#define cols 3
//too much space allocated
//can use realoc
//sizeof won't work. add variable of sizes for each array
//if fixed, each elemet *2 will be printed.

//'B' and B
//'B' and C

//2:
void digits(int a,int b){
    char str[20];
    if(a>b){
        sprintf(str, "%d", a);
        for(int i = 0;i<b;i++){
            printf("char is %c\n",str[i]);
        }
    }
    else{
        sprintf(str, "%d", b);
        for(int i = 0;i<a;i++){
            printf("char is %c\n",str[i]);
        }        
    }
}

int last(char* str, char ch){
    for(int i = strlen(str)-1;i>0;i--){
        if(str[i] == ch){
            return i;
        }
    }
    return -1;
}

void split_string(const char* str, char*** out_arr, int* num_words) {
    char* temp = strdup(str); // Duplicate the input string to tokenize
    char* token;
    int count = 0;

    // First pass: Count the number of words
    token = strtok(temp, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    free(temp); // Free the temporary string

    // Allocate memory for the array of pointers (N + 1 for NULL terminator)
    *out_arr = (char**)malloc((count + 1) * sizeof(char*));
    *num_words = count;

    // Second pass: Allocate memory for each word and store in out_arr
    temp = strdup(str); // Duplicate the string again
    token = strtok(temp, " ");
    int i = 0;
    while (token != NULL) {
        (*out_arr)[i] = strdup(token); // Allocate memory for each word
        i++;
        token = strtok(NULL, " ");
    }
    (*out_arr)[count] = NULL; // Set the last element to NULL for termination
    free(temp); // Free the temporary string
}

void free_split_result(char** arr, int num_words) {
    for (int i = 0; i < num_words; i++) {
        free(arr[i]); // Free each word
    }
    free(arr); // Free the array of pointers
}

struct Node;
typedef struct Node Node;

typedef struct Node  //חייב שם כי אני קורא לעצמי
{
    int** matrix;
    Node* next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
    int size;
}LinkedList;

void init_lst(LinkedList* lst){
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}
Node* create(int mat[rows][cols]){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(!new_node){
        printf("memory alloc failed\n");
        return;
    }
    new_node->matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        new_node->matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            new_node->matrix[i][j] = mat[i][j]; // Copy the values from input matrix
        }
    }
    new_node->next = NULL;
    return new_node;
}

void add(LinkedList* lst, int mat[rows][cols]){
    Node* to_add = create(mat);
    if(lst->tail){
        lst->tail->next = to_add;
    }
    else{
        lst->head = to_add;
    }
    lst->tail = to_add;
    lst->size++;
}

void print_elem(LinkedList* lst) {
    Node* current_node = lst->head; // Start at the head of the list
    int matrix_count = 1;           // Counter for the matrix number

    while (current_node != NULL) { // Traverse the linked list
        int** current_matrix = current_node->matrix; // Get the matrix of the current node
        printf("Matrix number: %d elements are:\n", matrix_count);

        // Print the 2D matrix
        for (int j = 0; j < rows; j++) {
            for (int z = 0; z < cols; z++) {
                printf("%d ", current_matrix[j][z]);
            }
            printf("\n"); // Newline after each row
        }
        printf("Moving to the next matrix!\n\n");

        current_node = current_node->next; // Move to the next node
        matrix_count++; // Increment the matrix counter
    }

    printf("Finished printing all matrices.\n");
}

void free_list(LinkedList* lst) {
    Node* current = lst->head; // Start at the head of the list

    while (current != NULL) {
        Node* next = current->next; // Save the pointer to the next node

        // Free the dynamically allocated 2D matrix
        for (int i = 0; i < rows; i++) {
            free(current->matrix[i]); // Free each row
        }
        free(current->matrix); // Free the array of row pointers

        // Free the current node
        free(current);

        // Move to the next node
        current = next;
    }

    // Set the head, tail, and size of the list to indicate it's empty
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}






int main(){
LinkedList list;
    init_lst(&list);

    // Create 3 matrices
    int mat1[rows][cols] = {{1, 2, 3}, {4, 5, 6}};
    int mat2[rows][cols] = {{7, 8, 9}, {10, 11, 12}};
    int mat3[rows][cols] = {{13, 14, 15}, {16, 17, 18}};

    // Add matrices to the list
    add(&list, mat1);
    add(&list, mat2);
    add(&list, mat3);

    // Print the matrices in the list
    printf("Printing matrices in the list:\n");
    print_elem(&list);

    // Free all nodes and matrices
    free_list(&list);

    return 0;
}