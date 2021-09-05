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