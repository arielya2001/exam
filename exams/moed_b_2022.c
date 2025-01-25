#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// typedef struct Node {
//     char *name;            // Employee's name
//     int emp_num;           // Employee number
//     struct Node *subordinates[5]; // Up to 5 direct subordinates
//     int subordinate_count; // Number of current subordinates
// } Node;



// Node* create(char* n,int num){
//     Node* new_employee = (Node*)malloc(sizeof(Node));
//     if(!new_employee){
//         printf("Malloc Failed!");
//         return NULL;
//     }
//     new_employee->emp_num = strdup(num);
//     new_employee->name = n;
//     new_employee->subordinate_count = 0;
//     return new_employee;
// }

// void add_subordinate(Node *manager, Node *employee) {
//     if (manager->subordinate_count < 5) {
//         manager->subordinates[manager->subordinate_count++] = employee;
//     } else {
//         printf("Manager %s cannot have more than 5 subordinates\n", manager->name);
//     }
// }

// void print_hierarchy(Node *manager) {
//     if (!manager) return;
//     printf("Manager: %s (ID: %d)\n", manager->name, manager->emp_num);
//     printf("Subordinates:\n");
//     for (int i = 0; i < manager->subordinate_count; i++) {
//         printf("  %s (ID: %d)\n", manager->subordinates[i]->name, manager->subordinates[i]->emp_num);
//     }
//     printf("\n");
// }


#include <stdio.h>
#include <string.h>

#define NUM_LETTERS ('z' - 'a' + 1)

// Prototype for the function used in `max_new_increase_substr`
int max_increase_with_memory_substr_from_start(char* string);

int max_new_increase_substr(char* string) {
    int max_letter_num = 0;

    // Iterate through the string
    while (*string) {
        int letter_num = max_increase_with_memory_substr_from_start(string);
        if (letter_num > max_letter_num) {
            max_letter_num = letter_num;
        }
        string++;
    }

    return max_letter_num;
}

int max_increase_with_memory_substr_from_start(char* string) {
    int used_letters[NUM_LETTERS] = {0}; // Track used letters
    char max_letter = *string;          // Track the largest character seen
    int max_letter_num = 1;             // Start with the current character

    used_letters[*string - 'a'] = 1;    // Mark the first character as used
    string++;                           // Move to the next character

    // Iterate through the rest of the string
    while (*string) {
        if (*string > max_letter) {  // If the current character is greater than the max seen
            max_letter = *string;
            used_letters[*string - 'a'] = 1; // if it's a it's in 0, it's b it's in 1
            max_letter_num++;  // Extend the substring
        } else if (used_letters[*string - 'a']) {  // If the character is already used
            max_letter_num++;  // Extend the substring
        } else {
            break;  // Otherwise, end the substring
        }
        string++;
    }

    return max_letter_num;
}

int main() {
    char* str = "abfaaczcak";
    printf("Answer is: %d\n", max_new_increase_substr(str)); // Should print 6
    return 0;
}
