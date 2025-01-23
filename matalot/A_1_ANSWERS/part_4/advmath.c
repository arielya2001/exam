#include "advmath.h"

float power(int base, int exp) {
    float result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

float square_root(int num) {
    float x = num;
    float y = 1;
    float epsilon = 0.000001;
    while(x - y > epsilon) {
        x = (x + y)/2;
        y = num/x;
    }
    return x;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

float average(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}