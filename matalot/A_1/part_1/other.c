#include <stdio.h>
#include "other.h"

int double_number(int x) {
    printf("Doubling the number %d\n", x);
    return x * 2;
}

void print_animal_noise(const char* animal) {
    if (strcmp(animal, "cat") == 0) {
        printf("Meow!\n");
    } else if (strcmp(animal, "dog") == 0) {
        printf("Woof!\n");
    } else {
        printf("Unknown animal noise...\n");
    }
}

int calculate_pizza_slices(int people) {
    // Assuming each person needs 2.5 slices and pizzas have 8 slices
    int total_slices_needed = people * 2.5;
    int pizzas_needed = (total_slices_needed + 7) / 8;  // Round up
    return pizzas_needed;
}