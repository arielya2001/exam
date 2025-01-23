// main.c
#include <stdio.h>
#include "mathlib.h"

int main() {
    int a = 10, b = 5;
    
    printf("Math operations with %d and %d:\n", a, b);
    printf("Addition: %d\n", add(a, b));
    printf("Subtraction: %d\n", subtract(a, b));
    printf("Multiplication: %d\n", multiply(a, b));
    printf("Division: %.2f\n", divide(a, b));
    
    return 0;
}