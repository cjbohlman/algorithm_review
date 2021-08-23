#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Queue {
    int maxSize;
    int *arr;
    int startIndex;
    int numElements;
};

typedef struct Queue Queue;

int empty(Queue *queue)
{
    return queue->numElements == 0;
}

int full(Queue *queue)
{
    return queue->numElements == queue->maxSize;
}

void enqueue(Queue *queue, int value) {
    if (full(queue)) {
        return;
    }
    queue->arr[(queue->startIndex + queue->numElements) % queue->maxSize] = value;
    queue->numElements += 1;
}

int dequeue(Queue *queue) {
    if (empty(queue)) return NULL;
    int val = queue->arr[queue->startIndex];
    queue->numElements--;
    queue->startIndex = (queue->startIndex + 1) % queue->maxSize;
    return val;
}

void print_queue(Queue *queue) {
    printf("Printing queue:\n");
    if (queue->numElements > 0) {
        int i = 0;
        do {
            printf("%d\n", queue->arr[(queue->startIndex + i) % queue->maxSize]);
            i++;
        } while (i != queue->numElements);
    }
}