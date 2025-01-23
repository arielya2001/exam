#include <stdio.h>
#include "other.h"

int main()
{
    // Test double_number
    int result = double_number(7);
    printf("Double of 7 is: %d\n", result);

    // Test animal noises
    print_animal_noise("cat");
    print_animal_noise("dog");
    print_animal_noise("elephant");

    // Test pizza calculator
    int pizzas = calculate_pizza_slices(10);
    printf("For 10 people, you need %d pizzas\n", pizzas);

    return 0;
}