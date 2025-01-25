#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

void initLinkedList(LinkedList *list);
int isEmptyLinkedList(LinkedList *list);
void append(LinkedList *list, char* str);
int removeFirst(LinkedList *list);
void displayLinkedList(LinkedList *list);
int linkedListSize(LinkedList *list);

#endif
