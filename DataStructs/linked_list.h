#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

void initLinkedList(LinkedList *list);
int isEmptyLinkedList(LinkedList *list);
void append(LinkedList *list, int value);
void prepend(LinkedList *list, int value);
int removeFirst(LinkedList *list);
void displayLinkedList(LinkedList *list);
int linkedListSize(LinkedList *list);

#endif
