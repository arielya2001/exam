#include "advmath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float average(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return (float)(sum) / (float)(size);
}
float power(int a, int b) {
    float ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a; // Multiply `ans` by the base `a`
    }
    return ans;
}

float square_root(int a) {
    if (a < 0) {
        printf("Error: Square root of a negative number is not defined.\n");
        return -1.0; // Error indicator
    }
    return sqrt((float)a); 
}

int factorial(int a){
    int ans =1;
    for(int i=1; i<=a;i++){
        ans*=i;
    }
    return ans;
}