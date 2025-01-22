#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void initLinkedList(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int isEmptyLinkedList(LinkedList *list) {
    return list->head == NULL;
}

void append(LinkedList *list, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (list->tail) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
    list->size++;
}

void prepend(LinkedList *list, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = list->head;
    if (!list->tail) {
        list->tail = newNode;
    }
    list->head = newNode;
    list->size++;
}

int removeFirst(LinkedList *list) {
    if (isEmptyLinkedList(list)) {
        printf("Linked list is empty. Cannot remove.\n");
        return -1;
    }
    Node *temp = list->head;
    int value = temp->data;
    list->head = list->head->next;
    if (!list->head) {
        list->tail = NULL;
    }
    free(temp);
    list->size--;
    return value;
}

void displayLinkedList(LinkedList *list) {
    Node *current = list->head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int linkedListSize(LinkedList *list) {
    return list->size;
}
