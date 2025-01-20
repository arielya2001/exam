#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h> 
#define MAX_NUMBERS 100 

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



int main(){
    // decline();
    targil9();
    return 0;
}