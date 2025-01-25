#define COLS 5 
#define ROWS 3 
#define N 4
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
//question 1.a:
//10 19 30 40 50

//2.a
//write COLS at least.
//2.b -  {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}}; //5
int Get_1D_Array (int arr[][COLS], int n) 
{ 
    int index = 0;
    for(int i =0;i<ROWS;i++){
        for(int j =0;j<COLS;j++){
            if(index == n){
                return arr[i][j];
            }
            index++;
        }
    }
}
void reverse_file_str(FILE *f){
    f = fopen("myfile.bin","ab+");
    int num=0;
    char *str;
    fread(&num,sizeof(int),1,f);
    fseek(f,-sizeof(char),SEEK_END);
    for(int i =0;i<num;i++){
        char ch;
        fread(&ch,sizeof(char),1,f);
        fwrite(&ch,sizeof(char),1,f);
        str[i] = ch;
        fseek(f,-2*(i+1)*sizeof(char)-1,SEEK_CUR);
    }
    fclose(f);
    printf("the opposite string is: %s",str);
}

//3.b:   ANSWER IS 17!
int f1(int a){ 
    return a+1; 
}
int applyArray(int (*ptr)(int), int arr[]){
    int sum  = 0;
    for(int i = 0;i<N;i++){
        arr[i] = (ptr)(arr[i]);
        sum+=arr[i];
    }
    return sum;
}

typedef struct {
    int rows;
    int cols;
    int **mat;
} matrix;

matrix* init_mat(int rows, int cols) {
    matrix* new_mat = (matrix*) malloc(sizeof(matrix)); // Allocate memory for the matrix struct
    new_mat->rows = rows;
    new_mat->cols = cols;

    new_mat->mat = (int**) malloc(rows * sizeof(int*)); // תצביע על מערך של פוינטרים למספרים, כלומר שורות
    for (int i = 0; i < rows; i++) {
        new_mat->mat[i] = (int*) calloc(cols, sizeof(int)); // כל שורה מצביעה על מערך של מספרים!
    }

    return new_mat; // Return the pointer to the allocated matrix
}

void collect(matrix* m, int arr[ROWS][COLS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            m->mat[i][j] = arr[i][j];
        }
    }
}

matrix* add(matrix* m1, matrix* m2){
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        printf("Error: Matrix dimensions do not match.\n");
        return NULL;
    }
    int r = m1->rows;
    int c = m1->cols;
    matrix *new_mat = init_mat(r,c);
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            new_mat->mat[i][j] = m1->mat[i][j] + m2->mat[i][j];
        }
    }
    return new_mat;
}

void print_mat(matrix* m){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%d",m->mat[i][j]);
        }
    }
}
void dest_mat(matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->mat[i]); // Free each row
    }
    free(m->mat); // Free the array of row pointers
    free(m); // Free the matrix structure itself
}







int main(){

    // int arr[4]={6,4,3,0}; 
    // int (*ptrFunc)(int);
    // ptrFunc = f1;
    // int result = applyArray(ptrFunc, arr); 
    // printf("%d\n", result); 
    return 0;  
}
