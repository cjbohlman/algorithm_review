#include<cassert>
#include<iostream>
#include<memory>
#include <stdexcept>

class Queue {
private:
    class Node {
    public:
        int val;
        std::shared_ptr<Node> next;
        Node(int);
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

public:
    Queue();
    bool empty();
    void enqueue(int);
    int dequeue();
    void print_queue();
};

Queue::Node::Node(int value) {
    val = value;
    next = nullptr;
}

Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}

bool Queue::empty() {
    return head == nullptr && tail == nullptr;
}

void Queue::enqueue(int value) {
    auto newNode = std::make_shared<Node>(Node{value});
    if (empty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}

int Queue::dequeue() {
    if (empty()) {
        throw std::out_of_range("Can't dequeue an empty queue");
    } 
    auto value = head->val;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    return value;
}

void Queue::print_queue() {
    auto qp = head;
    std::cout << "Printing queue" << std::endl;
    while (qp != nullptr) {
        std::cout << qp->val << std::endl;
        qp = qp->next;
    }
}
