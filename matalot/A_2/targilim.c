#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define N 50
#define MAX 100
#define INF 100000 // Representing infinity for unreachable paths
#define objects 5
void ex1(){
    int sum=0;
    int grade[N];
    for(int i =1;i<3;i++){
        int g;
        printf("enter grade for student: %d\n",i);
        scanf("%d",&g);
        printf("%d\n",g);
        sum+=g;
        grade[i-1] = g;
    }
    float avg = (float)(sum)/2;
    printf("the avg is: %.2f",avg);
    for(int j = 0;j<2;j++){
        if((float)(grade[j]) > avg){
            printf("you are above average: %d",grade[j]);
        }
    }
}

int is_pali(char* str1){
    int length = strlen(str1);
    for(int i =0;i<length/2;i++){
        if(str1[i] != str1[length-1-i]){
            printf("%s%s", str1, "is not palidnrom");
            return 0;
        }
    }
    printf("%s%s", str1, "is palidnrom");
    return 1;    
}

void transpose(int matrix[][MAX], int row, int col){
    for(int i = 0;i<row;i++){
        for(int j = i+1;j<col;j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;

        }
    }
}

void is_magic_square(int matrix[][MAX], int ROWS, int COLS) {
    // Calculate the sum of the first row
    int row_sum = 0;
    for (int j = 0; j < COLS; j++) {
        row_sum += matrix[0][j];
    }

    // Check row sums
    for (int i = 1; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
        if (sum != row_sum) {
            printf("it's not");
        }
    }

    // Check column sums
    for (int j = 0; j < COLS; j++) {
        int sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += matrix[i][j];
        }
        if (sum != row_sum) {
            printf("it's not");
        }
    }

    // Check diagonal sums
    int diag_sum1 = 0, diag_sum2 = 0;
    for (int i = 0; i < ROWS; i++) {
        diag_sum1 += matrix[i][i]; 
        diag_sum2 += matrix[i][ROWS - 1 - i];
    }

    if (diag_sum1 != row_sum || diag_sum2 != row_sum) {
        printf("it's not");
    }

    // All conditions satisfied
    printf("it's yes");
}

void shortest_path(int graph[][MAX], int row, int col, int start, int end){
     int dist[MAX][MAX];

    // Initialize the distance matrix with input graph
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Perform Floyd-Warshall algorithm
    for (int k = 0; k < row; k++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Print the shortest path from start to end
    printf("Shortest path from node %d to node %d: ", start, end);
    if (dist[start][end] == INF) {
        printf("No path exists.\n");
    } else {
        printf("%d\n", dist[start][end]);
    }
}
int comp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int knapsack( int values[objects], int weights[objects], int sackSize, int isSeleceted[objects]){
    int p_w[objects];
    for(int i =0;i<objects;i++){
        p_w[i] = (float)(values[i]) / (float)(weights[i]);
    }
    qsort(p_w,objects,sizeof(int),comp); //sort desecnding order
    int sum = 0;
    int j = 0;
    while(sum<sackSize){
        sum -=weights[j];
        isSeleceted[j] = 1;
    }
    return p_w[0];
}

void sub_array_size(void* place1, void* place2, int type){
    char* p1 = (char*)place1; //needed because char is 1 byte, so for example 1012-1000 = 12.
    char* p2 = (char*)place2; //if it was int* for example, it would be 12/4 = 3!
    int number = (p1 - p2)/type;
    printf("The subarray size between the two given pointers is: %d", number);
}

void find_pair_with_sum(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            printf("Number %d at index %d and number %d at index %d sum is %d as required\n", arr[left], left, arr[right], right, target);
            return;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    printf("No such numbers exist in the given array\n");
}

int is_inside(int a[], int element, int size){
    for(int i = 0;i<size;i++){
        if(a[i] == element){
            return 1;
        }
    }
    return 0;
}

int first_one(int arr[], int size) {
    bool visited[MAX] = {false}; // Track visited indices
    int i = 0; // Start at the first index

    while (i >= 0 && i < size) { // Ensure we stay within bounds
        int nextIndex = i + arr[i]; // Calculate the next index to jump to

        if (nextIndex >= 0 && nextIndex < size && visited[nextIndex]) {
            return i; // Return the current index before the jump
        }

        visited[i] = true; // Mark the current index as visited
        i = nextIndex; // Jump to the next index
    }

    return -1; // If traversal goes out of bounds, no repeated visits
}

int* find_subsequence(int A[], int sizeA, int B[], int sizeB, int *start_ptr, int *end_ptr) {
    int i = 0; // Index for array A
    int j = 0; // Index for array B

    while (i < sizeA && j < sizeB) {
        if (A[i] == B[j]) {
            if (j == 0) {
                *start_ptr = &A[i]; // Store the starting pointer
            }
            j++;
        }
        i++;
    }

    if (j == sizeB) { // If we've matched all elements of B
        *end_ptr = &A[i - 1]; // Store the ending pointer
        return *start_ptr; // Return the starting pointer
    }

    return NULL; // B is not a subsequence of A
}



int main(){
    // ex1();
    // is_pali("abba");
    // int matrix[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int n = 3;

    // printf("Original Matrix:\n");
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }

    // transpose(matrix, n,n);

    // printf("\nTransposed Matrix:\n");
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    int arr[] = {3, 2, 0, 1, -3};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int result = first_one(arr, size); // Pass the array and its size
    printf("the index is: %d", result);
    return 0;
}