// main.c
#include <stdio.h>
#include "mathlib.h"
#include "advmath.h"

int main() {
    int a = 10, b = 5;
    
    // Using static library (basic math)
    printf("Basic operations with %d and %d:\n", a, b);
    printf("Sum: %d\n", add(a, b));
    printf("Product: %d\n", multiply(a, b));
    
    // Using dynamic library (advanced math)
    printf("\nAdvanced operations:\n");
    printf("%d to the power of %d = %.2f\n", a, b, power(a, b));
    printf("Square root of %d = %.2f\n", a, square_root(a));
    
    // Mixing both
    int numbers[] = {2, 4, 6, 8, 10};
    float avg = average(numbers, 5);
    printf("\nMixed calculation:\n");
    printf("Average of numbers = %.2f\n", avg);
    printf("Average multiplied by 2 = %d\n", multiply(avg, 2));
    
    return 0;
}