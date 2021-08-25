#include "queue_arr.hpp"

int main() {
    Queue queue{10};
    assert(queue.empty());
    assert(!queue.full());
    try {
        assert(!queue.dequeue());
        assert(1==0);
    } catch(...) {}

    queue.enqueue(1);
    assert(!queue.empty());
    assert(!queue.full());

    assert(1 == queue.dequeue());
    assert(queue.empty());
    assert(!queue.full());
    try {
        assert(!queue.dequeue());
        assert(1==0);
    } catch(...) {}

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    assert(!queue.empty());
    assert(!queue.full());

    assert(1 == queue.dequeue());
    assert(!queue.empty());
    assert(2 == queue.dequeue());
    assert(!queue.empty());
    assert(3 == queue.dequeue());
    assert(queue.empty());
    assert(!queue.full());

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    assert(!queue.empty());
    assert(queue.full());

    try {
        queue.enqueue(10);
        assert(1==0);
    } catch(...) {}
}