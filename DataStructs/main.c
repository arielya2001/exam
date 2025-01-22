#include "queue.h"
#include "stack.h"
#include "linked_list.h"
#include "binary_tree.h"
#include <stdio.h>

int main() {
    // Queue demonstration
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Dequeued: %d\n", dequeue(&q));

    // Stack demonstration
    Stack s;
    initStack(&s);
    push(&s, 30);
    push(&s, 40);
    printf("Popped: %d\n", pop(&s));

    // Linked list demonstration
    LinkedList list;
    initLinkedList(&list);
    append(&list, 50);
    append(&list, 60);
    displayLinkedList(&list);

    // Binary tree demonstration
    TreeNode *root = NULL;
    root = insert(root, 70);
    root = insert(root, 80);
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}