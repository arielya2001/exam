#include "stack.h"
#include <stdio.h>

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack overflow. Cannot push %d.\n", value);
        return;
    }
    s->items[++s->top] = value;
    printf("Pushed: %d\n", value);
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack underflow. Cannot pop.\n");
        return -1;
    }
    return s->items[s->top--];
}

int peek(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    }
    return s->items[s->top];
}

void printStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}
