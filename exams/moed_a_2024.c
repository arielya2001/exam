#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
#define MASK 248 

// int main(int argc,char **argv){
//     if(argc==1){
//         printf("No string found");
//         return 1;
//     }
//     if(argc == 2){
//         printf("only 1 string: %s",argv[1]);
//     }
//     int amount = 1;
//     char* str = argv[1];
//     for(int i =2;i<argc;i++){
//         if(!strcmp(str,argv[i])){
//             amount++;
//         }
//     }
//     printf("%s%s%d%s",str,"appears ",amount," times");
//     return 0;
// }

int main(){


}

typedef struct{
    int elem1;
    long elem2;
}my_struct;

my_struct** create(){
    int size;
    printf("enter size of array: \n");
    scanf("%d\n",&size);
    my_struct** array = (my_struct**)malloc(sizeof(my_struct*)*size);
    if(!array){
        printf("alloc failed!");
        return NULL;
    }
    for(int i =0;i<size;i++){
        int n1;
        long n2;
        my_struct* struct_add = (my_struct*)malloc(sizeof(my_struct));
        if (!struct_add) {
            printf("Allocation failed!\n");
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
        printf("enter first element(int): \n");
        scanf("%d\n",&n1);             
        printf("enter second element(long): \n");
        scanf("%ld\n",&n2);
        struct_add->elem1 = n1;
        struct_add->elem2 = n2;
        array[i] = struct_add;
    }
    return array;
}

void write_to_file(my_struct** array, void(*fptr)(char*,my_struct*)){
    int i = 0;
    char* file_name = (char*)malloc(sizeof(char)*MAX_SIZE);
    if(!file_name){
        printf("malloc failed!\n");
        return;
    }
    printf("enter file name, up to 100 chars!: \n");
    scanf("%s",file_name);
    while(array[i]!=NULL){
        fptr(file_name,array[i]);
        i++;
    }
    free(file_name);
}

void write_elem(char* file_name, my_struct* data){
    FILE* p = fopen(file_name,"a");
    if(!p){
        printf("opening failed!");
        exit(1);
    }
    int num1 = data->elem1;
    long num2 = data->elem2;
    fprintf(p,"%d%ld",num1,num2);
    fclose(p);
}   

my_struct* struct_find(int index){
    char* file_name = (char*)malloc(sizeof(char)*MAX_SIZE);
    if(!file_name){
        printf("malloc failed!\n");
        return;
    }
    printf("enter file name, up to 100 chars!: \n");
    scanf("%s",file_name);
    FILE* p = fopen(file_name,"r");
    if(!p){
        printf("opening failed!");
        return;
    }
    int num1;
    long num2;
    for (int i = 0; i <= index; i++) {
        if (fscanf(p, "%d %ld", &num1, &num2) != 2) {
            printf("Error: Reached end of file before finding the record\n");
            fclose(p);
            return;
        }
    }
    fclose(p);
    free(file_name);
    my_struct* ans = (my_struct*)malloc(sizeof(my_struct));
    if(!ans){
        printf("malloc failed!");
        return NULL;
    }
    ans->elem1 = num1;
    ans->elem2 = num2;
    return ans;
}

void print_all(){
    my_struct** test = create();
    char* file_name = "test.txt";
    void(*fptr)(char*,my_struct*);
    fptr = write_elem;
    write_to_file(test,fptr);
    my_struct* ans = struct_find(5);
    printf("answer is: %d%ld",ans->elem1,ans->elem2);
}


void bits_ex(){
    int ArrOne[8] = {0};
    int ArrTwo[8] = {0};
    unsigned val=0;
    for(int i = 0;i<8;i++){
        int number1;
        printf("enter a number for array1: \n");
        scanf("%d",&number1);
        ArrOne[i] = number1;
    }
    int temp[8] = {0};
    for(int j=0;j<8;j++){
        int number2;
        printf("enter a number for array2, must be 1-8: \n");
        scanf("%d",&number2);
        while(number2<1 || number2>8 || temp[number2-1]==1){
            printf("enter a number for array2, must be 1-8 and not used before!: \n");
            scanf("%d",&number2);
        }
        ArrTwo[j] = number2;
        temp[number2-1] = 1;
    }
    for(int i = 0;i<8;i++){
        int index_bit_array2 = ArrTwo[i];
        int number_work = ArrOne[i]; 
        //now we need to take the index_bit_array2 bit from number_work
        unsigned bit_extracted = (number_work >> index_bit_array2-1)&1;
        //now i have the bit. we need to place him in the i-th index of val.
        val|= (bit_extracted << i);
        //setting the i-th bit of val to the bit we extracted!
    } 
}

typedef struct{
    unsigned int bit : 1; 
}bitfield;

void bits_with_bitfield(){
    bitfield bitField;
    int ArrOne[8] = {0};
    int ArrTwo[8] = {0};
    unsigned val=0;
    for(int i = 0;i<8;i++){
        int number1;
        printf("enter a number for array1: \n");
        scanf("%d",&number1);
        ArrOne[i] = number1;
    }
    int temp[8] = {0};
    for(int j=0;j<8;j++){
        int number2;
        printf("enter a number for array2, must be 1-8: \n");
        scanf("%d",&number2);
        while(number2<1 || number2>8 || temp[number2-1]==1){
            printf("enter a number for array2, must be 1-8 and not used before!: \n");
            scanf("%d",&number2);
        }
        ArrTwo[j] = number2;
        temp[number2-1] = 1;
    }
    for(int i = 0;i<8;i++){
        int index_bit_array2 = ArrTwo[i];
        int number_work = ArrOne[i]; 
        //now we need to take the index_bit_array2 bit from number_work
        bitField.bit = (number_work >> index_bit_array2-1)&1;
        //now i have the bit. we need to place him in the i-th index of val.
        val|= (bitField.bit << i);
        //setting the i-th bit of val to the bit we extracted!
}
}

void calc(unsigned val){
    //we have val, and we need to extract bits 3-7. i will use MASK as defind = 248
    // i did 248 because 2^3 + 2^4 + ... + 2^7 = 248
    int ans = (val & MASK)>>3;
    printf("the answer is: %d", ans);
}


     





