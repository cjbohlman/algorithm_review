#include "queue_ll.h"

int main() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
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
    assert(2 == dequeue(queue));
    assert(!empty(queue));
    assert(3 == dequeue(queue));
    assert(empty(queue));
    print_queue(queue);

    free(queue);
}