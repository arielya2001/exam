#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100
#define MASK_1 1020 // from index 2 to 9
#define MASK_2 261120 //from index 10 to 17
void modifyArrayGeneric(void* array, int size, int sizeOfElement, void* (*genericFunction)()) {
    for (int i = 0; i < size; i++) {
        void* element = (char*)array + i * sizeOfElement; // Get the i-th element
        genericFunction(element); // Call the generic function on the element
    }
}

void swap(void *a, void *b, size_t size){
    char *p = a; //p is a pointer to char, now p points to the same memory location of a
    char *q = b;
    for(int i=0;i<size;i++){
        char temp = p[i];  //one byte saved
        p[i] = q[i];
        q[i] = temp;
    }
}

void reverse(int size){
    char* arr[size];
    for(int i = 0;i<size;i++){
        char name[MAX];
        printf("enter a name: \n");
        scanf("%s",name);
        arr[size-i-1] = strdup(name);
    }
    for(int j = 0;j<size;j++){
        char* name_i = arr[j];
        for(int z = 0;z< strlen(name_i)/2;z++){
            if(name_i[z] != name_i[strlen(name_i)-z-1]){
                swap(&name_i[z],&name_i[strlen(name_i)-z-1],sizeof(char));
            }
        }
        arr[j] = name_i;
        printf("the opposite name is: %s\n",arr[j]);
    }
}


void encode(char ch){
    int value;
    if(ch >='a' && ch<='z'){
        int index = ch - 'a'+1;
        value = (index<<1) |1;
    }
    else{
        int index = ch - 'A'+1;
        value = (index<<1);
    }
}

void encode2(char ch1, char ch2){
    unsigned int value=0;
    int index_1;
    int index_2;
    if(ch1 >='a' && ch1<='z'){
        index_1 = ch1 - 'a'+1;
        value |= (1 << 1);
    }
    else{
        index_1 = ch1 - 'A'+1;
    }
    value |= (index_1 << 2);

    if(ch2 >='a' && ch2<='z'){
        index_2 = ch2 - 'a'+1;
        value = value|(1>>0);
     }
    else{
        index_2 = ch2 - 'A'+1;
    }
    value = value |(index_2<<10);
}

typedef struct {
    unsigned int is_lowercase : 1; // 1 bit: 1 for lowercase, 0 for uppercase
    unsigned int char_index : 6;  // 6 bits: Alphabetical index (1-26)
} EncodedChar;

void encode_char(char ch, EncodedChar *encoded) {
    if (ch >= 'a' && ch <= 'z') { // Lowercase
        encoded->is_lowercase = 1;          // Set the LSB to 1
        encoded->char_index = ch - 'a' + 1; // Store the index (1-26)
    } else if (ch >= 'A' && ch <= 'Z') { // Uppercase
        encoded->is_lowercase = 0;          // Set the LSB to 0
        encoded->char_index = ch - 'A' + 1; // Store the index (1-26)
    }
}

void print_encoded_char(EncodedChar encoded) {
    printf("Character index: %d\n", encoded.char_index);
    printf("Is lowercase: %d\n", encoded.is_lowercase);
    printf("Binary representation: ");
    unsigned int *raw_value = (unsigned int *)&encoded;
    for (int i = sizeof(EncodedChar) * 8 - 1; i >= 0; i--) {
        printf("%d", (*raw_value >> i) & 1);
    }
    printf("\n");
}

void write(char* array[], char* name) {
    FILE* f = fopen(name, "w"); 
    if (!f) {
        printf("failed to open!");
        return;
    }
    int i = 0;
    while (array[i]) { 
        char* string = array[i];
        int size = strlen(string);
        if (fprintf(f, " %d %s", size, string) < 0) {
            printf("Failed to write! \n");
            break; 
        }
        i++;
    }
    fclose(f);
}
void restore(char* name) {
    FILE* f = fopen(name, "rb"); 
    if (!f) {
        printf("failed to open!");
        return;
    }
    char** array = (char**)malloc(sizeof(char*)*MAX);
        if (!array) {
        printf("Memory allocation failed for array!");
        fclose(f);
        return;
    }
    int i = 0;
    while (!feof(f)) { 
        int size_of_string;
        char ch1_ch3;
        fread(&ch1_ch3,sizeof(char),1,f);
        fread(&size_of_string,sizeof(int),1,f);
        char* to_add = (char*)malloc(sizeof(char)*size_of_string+1);
        if (!to_add) {
            printf("allocation failed\n");
            break;
        }
        fread(&ch1_ch3,sizeof(char),1,f);
        fread(to_add,sizeof(char),size_of_string,f);
        array[i] = to_add;
        i++;
    }
    realloc(array,sizeof(char*)*i);
    fclose(f);
}





int main(){
    // int a = 5;
    // int b = 3;
    // swap(&a,&b,sizeof(int));
    // double c = 5;
    // double d = 3;
    // swap(&c,&d,sizeof(double));
    // reverse(4);
    return 0;
}