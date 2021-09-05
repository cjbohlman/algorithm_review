#include "queue_ll.hpp"

int main() {
    Queue queue{};
    assert(queue.empty());
    try {
        assert(!queue.dequeue());
        assert(1==0);
    } catch(...) {}

    queue.enqueue(1);
    assert(!queue.empty());
    
    assert(1 == queue.dequeue());
        assert(queue.empty());
    try {
        assert(!queue.dequeue());
        assert(1==0);
    } catch(...) {}

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    assert(!queue.empty());
    
    assert(1 == queue.dequeue());
    assert(!queue.empty());
    assert(2 == queue.dequeue());
    assert(!queue.empty());
    assert(3 == queue.dequeue());
    assert(queue.empty());
}