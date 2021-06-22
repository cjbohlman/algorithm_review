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

int main() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->maxSize = 10;
    queue->arr = (int *) malloc(queue->maxSize * sizeof(int));
    queue->startIndex = 0;
    queue->numElements = 0;

    assert(empty(queue));
    assert(!dequeue(queue));
    print_queue(queue);

    enqueue(queue, 1);
    assert(!empty(queue));
    print_queue(queue);

    assert(1 == dequeue(queue));
    print_queue(queue);
    assert(empty(queue));
    assert(!dequeue(queue));

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    assert(!empty(queue));
    print_queue(queue);

    assert(1 == dequeue(queue));
    assert(!empty(queue));
    print_queue(queue);
    assert(2 == dequeue(queue));
    assert(!empty(queue));
    print_queue(queue);
    assert(3 == dequeue(queue));
    assert(empty(queue));
    print_queue(queue);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7);
    enqueue(queue, 8);
    enqueue(queue, 9);
    enqueue(queue, 10);
    print_queue(queue);
    assert(!empty(queue));
    assert(full(queue));

    enqueue(queue, 11);

    free(queue->arr);
    free(queue);
}