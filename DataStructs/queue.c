#include "queue.h"
#include <stdio.h>

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isQueueEmpty(Queue *q) {
    return q->size == 0;
}

int isQueueFull(Queue *q) {
    return q->size == MAX_SIZE;
}

void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;//updating rear index
    q->items[q->rear] = value; //putting in the array rear index the value
    q->size++; //updating current size of queue
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *q) { //remember that it's returning also
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
}

int front(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->items[q->front];
}

int queueSize(Queue *q) {
    return q->size;
}
