#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#define MAX_NUMBERS 100
#define MAX_SIZE 100 
#define N

void swap(void *a, void *b, size_t size){
    char *p = a; //p is a pointer to char, now p points to the same memory location of a
    char *q = b;
    for(int i=0;i<size;i++){
        char temp = p[i];  //one byte saved
        p[i] = q[i];
        q[i] = temp;
    }
}
int decline() {
    int numbers[MAX_NUMBERS];
    int count = 0; // Number of integers entered
    int num;

    printf("Enter numbers (end input with 0):\n");

    // Input numbers until the user enters 0
    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (count < MAX_NUMBERS) {
            numbers[count] = num;
            count++;
        } else {
            printf("Maximum number limit reached.\n");
            break;
        }
    }

    // If less than 5 numbers were entered, print all of them
    if (count < 5) {
        printf("Less than 5 numbers were entered. Printing all numbers:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", numbers[i]);
        }
    } else {
        // Print the last 5 numbers in order of input
        printf("Last 5 numbers entered:\n");
        for (int i = count - 5; i < count; i++) {
            printf("%d ", numbers[i]);
        }
    }

    printf("\n");
}

int targil9(){
    int k,a;
    printf("Enter the k: \n");
    scanf("%d", &k);
    int arr[10] = {0};
    for(int z = 0;z<10;z++){
        printf("Enter a number for the lst: \n");
        scanf("%d", &a);
        arr[z] = a;
    }
    int count = 0;
    int ans1,ans2;
    for(int i =0;i<10;i++){
        for(int j =i+1;j<10;j++){
            if(arr[i] + arr[j] == k){
                printf("we found the numbers!: %d%d",arr[i],arr[j]);
                return 0;
            }
        }
    }
    printf("NOT FOUND.\n");
}

// void targil10(int arr[N][N]){
//     int ans = 0;
//     for(int i=0;i<N;i++){
//             if(i==4){
//             break;
//         }
//         int current = 0;
//         for(int j=1;j<N;j++){
//             if(arr[j][i] >=arr[j-1][i]){
//                 current++;
//             }
//         }
//         if(current > ans){
//             ans = current;
//         }
//     }
//     printf("the answer is: %d\n",ans);

// }

int len1(int arr[], int *last){
    return (last - arr)+1;
}

int num(int **arr, int len){
    int count=0;
    for(int i =0;i<len;i++){
        if(arr[i] == NULL){
            count++;
        }
    }
    return count;
}

char* strcat1(char* dest, char* src){
    char *str12 = dest+ strlen(dest);
    while(*src!= '\0'){
        *str12 = *src;
        str12++; 
        src++;
    }
    *str12 = '\0';
    return dest;
}

void checks(char *s1, char *s2){
    int index = strlen(s1) - strlen(s2);
    if(strlen(s2) > strlen(s1)){
        printf("false\n");
        return;
    }
    int flag = 1;
    while(*s2!='\0'){
        if(s1[index] != *s2){
            printf("false");
            flag = 0;
            break;
        }
        index++;
        s2++;
    }
    if(flag){
        printf("true");
    }
}

char upCase(char c){
    if(c>= 'a' && c<= 'z'){
        return c - 'a' + 'A';
    }
    return c;
}

void reverse(char *s, int len){
    for(int i =0;i<len/2;i++){
        swap(&s[i], &s[len-1-i],sizeof(char));
    }
}

void num2str(unsigned int num, char *str){
    int dignum = 1, i;
    unsigned int tempnum = num;
    while(tempnum >9){ //calculate numbers of digits.
        tempnum/=10;
        dignum++;
    }
    str[dignum] = 0; //end of string
    while(dignum>0){
        dignum--;
        str[dignum] = num%10 + '0';
        num/=10;

    }
}
//linked list
typedef struct Node{
    int data;
    struct Node* next;
} Node;

// node ** because the node itself is a pointer, so we need the adress of it.
void deleteFirst(Node **h){
    if(!*h){
        return ;
    }
    Node *p = *h; // נוד זמני שיהיה הראש
    *h = p->next; // h points to the next node
    free(p);
}
//create new node
Node* newNode(int data, Node *next){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = next;
    return p;
}
//insert a new node in the end of the linked list
void insertLast(int data, struct Node **head){
    struct Node **p = head;
    while(*p){
        p = &((*p)->next);
    }
    *p = newNode(data,NULL);
}
//one approach
void delete1(struct Node **head, int data){
    struct Node **p = head;
    while(*p){
        if((*p)->data == data){
            deleteFirst(head);
        }
        else{
            p = &(*p)->next;
        }
    }
}
//second approach
void delete2(int data, Node** h){
    if (!*h){
        return;
    }
    Node *p = *h;
    Node **prev = h;
    while (p){
        if(p->data == data){
            *prev = p->next; // skip the current one! prev is now points to the node after the next one
            free(p);
            p = *prev; // p is now points to the node after the next one as i said above
        }
        else{
            prev = &(p->next);
            p = p->next;
        }
    }
}

union Data{
    char chars[21];
    int numbers[6];
};

struct BitField{
    unsigned bit : 1; 
};

unsigned and_using_bitfields(unsigned x, unsigned y, int n) {
    struct BitField bitX, bitY; // Define two bitfield structures

    // Extract the n-th bit of x and y using bitwise shift
    bitX.bit = (x >> n) & 1;
    bitY.bit = (y >> n) & 1;

    // Perform AND operation on the extracted bits
    unsigned result = bitX.bit & bitY.bit;

    // Return the result of the AND operation
    return result;
}

unsigned and_using_masks(unsigned x, unsigned y, int n) {
    int result = 0;
    for(int i =0;i<n;i++){
        unsigned bit_x  = (x>>i) &1;


    }
}

struct BitField2{
    unsigned int type : 3;
    unsigned int color : 4;
    unsigned int wheels : 3;
    unsigned int electric : 1;
};

void opp(){
    FILE *f = fopen("myfile.bin", "rb");
    if (f == NULL){
        printf("Unable to open file\n");
        return;
    }
    int num;
    fread(&num,sizeof(int),1,f);
    char string[num+1];
    memset(string, 0, sizeof(string)); 
    fseek(f,sizeof(int),SEEK_SET);
    fread(string, sizeof(char), num,f);
    fclose(f);
    for (int i =0;i<num/2;i++){
        if(string[i]!=string[num-1-i]){
            swap(&string[i], &string[num-1-i],sizeof(char));
    }
    }
    FILE *f2 = fopen("myfile.bin", "ab");
    if (f2 == NULL) {
        printf("Unable to open file for appending\n");
        return;
    }
    fwrite(string,sizeof(char),num,f2);
    fclose(f2);
    printf("the string is now: %s", string);
}

void oop2(){
    FILE* fp = fopen("myfile.bin", "ab+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1; 
    }
    int size = 0;
    fread(&size, sizeof(size), 1, fp);

    fseek(fp, -sizeof(char), SEEK_END);

    for (int i = 0; i < size; i++) {
        char ch;
        fread(&ch, sizeof(ch), 1, fp);
        fwrite(&ch, sizeof(ch), 1, fp);
        fseek(fp, -2 * (i + 1) * sizeof(char) - 1, SEEK_END); //everytime read and write char to file, in the end it's appending the string in opposite order
    }

    fclose(fp);
}

int is_same_files(char *name1, char *name2) {
    FILE *f1, *f2;
    int c1, c2;  // Use int to correctly store EOF
    f1 = fopen(name1, "r");
    f2 = fopen(name2, "r");

    // Check if files are successfully opened
    if (!f1 || !f2) {
        if (f1) fclose(f1);  // Close f1 if it was opened
        if (f2) fclose(f2);  // Close f2 if it was opened
        return -1;  // Indicate an error in opening files
    }

    // Compare characters until a difference is found or EOF is reached
    do {
        c1 = fgetc(f1); //c1 = -1 if we reach EOF.
        c2 = fgetc(f2);
    } while (c1 != EOF && c2 != EOF && c1 == c2);

    fclose(f1);
    fclose(f2);

    // If both files reached EOF, they are the same
    return (c1 == EOF && c2 == EOF);
}






int main() {
    // int account;         // account number
    // char name[30];       // account name
    // double balance;      // account balance
    // FILE *cfPtr;         // cfPtr = file pointer

    // // Open the file. Exit program if unable to create file
    // if ((cfPtr = fopen("account.txt", "w")) == NULL) {
    //     printf("File could not be opened\n");
    // } else {
    //     printf("Enter the account, name, and balance.\n");
    //     printf("Enter EOF to end input.\n");
    //     printf(">> ");

    //     // Write account, name, and balance into the file
    //     while (!feof(stdin)) {
    //         scanf("%d%s%lf", &account, name, &balance);
    //         fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
    //         printf(">> ");
    //     }

    //     fclose(cfPtr); // Close the file
    // }
    // opp();
    return 0;
}

