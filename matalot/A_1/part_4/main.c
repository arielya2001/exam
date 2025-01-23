// main.c
#include <stdio.h>
#include "advmath.h"

int main() {
    printf("Advanced Math Operations:\n");
    printf("2^3 = %.2f\n", power(2, 3));
    printf("Square root of 16 = %.2f\n", square_root(16));
    printf("Factorial of 5 = %d\n", factorial(5));
    
    int numbers[] = {2, 4, 6, 8, 10};
    printf("Average of [2,4,6,8,10] = %.2f\n", average(numbers, 5));
    
    return 0;
}