#include<cassert>
#include<iostream>
#include<memory>
#include <stdexcept>
#include <queue>

class Queue {
private:
    std::queue<int> queue;

public:
    bool empty();
    void enqueue(int);
    int dequeue();
    void print_queue();
};

bool Queue::empty() {
    return queue.empty();
}

void Queue::enqueue(int value) {
    queue.push(value);
}

int Queue::dequeue() {
    if (empty()) {
        throw std::out_of_range("Can't dequeue an empty queue");
    } 
    auto value = queue.front();
    queue.pop();
    return value;
}