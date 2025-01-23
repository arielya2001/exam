#include <stdio.h>
#include <stdlib.h>
#include "mathlib.h"



int add(int a, int b){
    return a+b;
}
int subtract(int a, int b){
    return a-b;
}
int multiply(int a, int b){
    return a*b;
}
float divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0.0; // Return 0 or handle the error as needed
    }
    return (float)a / (float)b; // Cast to float to perform floating-point division
}
