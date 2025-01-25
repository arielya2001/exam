#include "str_list.h"
#include <stdlib.h>
#include <string.h>

void initLinkedList(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int isEmptyLinkedList(LinkedList *list) {
    return list->head == NULL;
}

void append(LinkedList *list, char* str){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }    
    newNode->str = str;
    newNode->next = NULL;
    if (list->tail) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
    list->size++;
}