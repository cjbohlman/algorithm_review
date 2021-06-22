#include<cassert>
#include<iostream>
#include<memory>
#include <stdexcept>
#include <vector>

class Queue {
private:
    std::vector<int> data;
    int startIndex;
    int numElements;
    int maxSize;

public:
    Queue(int);
    bool empty();
    bool full();
    void enqueue(int);
    int dequeue();
    void print_queue();
};

Queue::Queue(int capacity) {
    maxSize = capacity;
    data = std::vector<int>(maxSize);
    startIndex = 0;
    numElements = 0;
}

bool Queue::empty() {
    return numElements == 0;
}

bool Queue::full() {
    return numElements == maxSize;
}

void Queue::enqueue(int value) {
    if (full()) throw std::out_of_range("Can't enqueue a full queue");
    data.at((startIndex + numElements) % maxSize) = value;
    numElements++;

}

int Queue::dequeue() {
    if (empty()) {
        throw std::out_of_range("Can't dequeue an empty queue");
    } 
    auto value = data.at(startIndex);
    startIndex++;
    numElements--;
    return value;
}

void Queue::print_queue() {
    std::cout << "Printing queue" << std::endl;
    for(int i = 0; i < numElements; i++) {
        std::cout << data.at((startIndex + i) % maxSize) << std::endl;
    }
}

int main() {
    Queue queue{10};
    assert(queue.empty());
    assert(!queue.full());
    try {
        assert(!queue.dequeue());
        assert(1==0);
    } catch(...) {}
    queue.print_queue();

    queue.enqueue(1);
    assert(!queue.empty());
    assert(!queue.full());
    queue.print_queue();

    assert(1 == queue.dequeue());
    queue.print_queue();
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
    queue.print_queue();

    assert(1 == queue.dequeue());
    assert(!queue.empty());
    assert(2 == queue.dequeue());
    assert(!queue.empty());
    assert(3 == queue.dequeue());
    assert(queue.empty());
    assert(!queue.full());
    queue.print_queue();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    queue.print_queue();
    assert(!queue.empty());
    assert(queue.full());

    try {
        queue.enqueue(11);
        assert(1==0);
    } catch(...) {}
}