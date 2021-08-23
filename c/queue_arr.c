#include "queue_arr.h"

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