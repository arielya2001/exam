#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdbool.h> 
#include <stdlib.h> 
#define MAX_NUMBERS 100 
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

void targil10(int arr[N][N]){
    int ans = 0;
    for(int i=0;i<N;i++){
            if(i==4){
            break;
        }
        int current = 0;
        for(int j=1;j<N;j++){
            if(arr[j][i] >=arr[j-1][i]){
                current++;
            }
        }
        if(current > ans){
            ans = current;
        }
    }
    printf("the answer is: %d\n",ans);

}

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





int main(){
    // int a = 1, b = 2;
    // int *arr[] = {&a, NULL, &b, NULL}; // Array of integer pointers
    // int len = 4;

    // int null_count = num(arr, len);
    // printf("Number of NULL elements: %d\n", null_count);
    // decline();
    // targil9();
    // char* str1 = "ariel           ";
    // char* str2 = "yaacobi";
    // char* ans = strcat1(str1,str2);
    // for(int i =0;i<strlen(ans);i++){
    //     printf("%c",ans[i]);
    // }
    // char arr[] = "Hello\0World!\0nigger\0";
    // swap_first_last(arr);
    // printf("%s\n",arr);
    return 0;
}