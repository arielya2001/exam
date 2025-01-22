#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int front(Queue *q);
int queueSize(Queue *q);

#endif
