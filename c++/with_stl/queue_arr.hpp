#include<cassert>
#include<iostream>
#include<memory>
#include <stdexcept>
#include <vector>

class Queue {
private:
    std::vector<int> data;
    int start;
    int end;

public:
    Queue(int);
    bool empty();
    bool full();
    void enqueue(int);
    int dequeue();
    void print_queue();
};

Queue::Queue(int capacity) {
    data = std::vector<int>(capacity); // holds n - 1 elements
    start = 0;
    end = 0;
}

bool Queue::empty() {
    return start == end;
}

bool Queue::full() {
    return (end + 1) % data.size() == start;
}

void Queue::enqueue(int value) {
    if (full()) throw std::out_of_range("Can't enqueue a full queue");
    data.at(end) = value;
    end = (end + 1) % data.size();

}

int Queue::dequeue() {
    if (empty()) {
        throw std::out_of_range("Can't dequeue an empty queue");
    } 
    auto value = data.at(start);
    start++;
    return value;
}