#include <stdexcept>
#include <memory>
#include <cassert>
#include <iostream>
#include <forward_list>

class LinkedList{
private:
    std::forward_list<int> data;
    void outOfRange();
public:
    int getSize();
    bool isEmpty();
    int valueAt(int);
    void pushFront(int);
    int popFront();
    void pushBack(int);
    int popBack();
    int front();
    int back();
    void insert(int, int);
    void erase(int);
    int value_n_from_end(int);
    void reverse();
    void removeValue(int);
    void printList();
};

inline void LinkedList::outOfRange() 
{
    throw std::out_of_range("Index out of range");
}

int LinkedList::getSize() {
    return std::distance(data.begin(), data.end());
}

bool LinkedList::isEmpty() {
    return data.empty();
}

void LinkedList::printList() {
    std::cout << "Printing LL of size: " << getSize() << std::endl;
    for(auto it = data.begin(); it != data.end(); it++) {
        std::cout << *it << std::endl;
    }
}

int LinkedList::valueAt(int index) {
    if (index < 0 || index >= getSize()) outOfRange();
    auto it = data.begin();
    for(int i = 0; i < index; i++) it++;
    return *it;
}

void LinkedList::pushFront(int value) {
    data.push_front(value);
}

int LinkedList::popFront()
{
    if (getSize() < 1) outOfRange();
    auto value = *data.begin();
    data.pop_front();
    return value;
}

void LinkedList::pushBack(int value) {
    if (getSize() == 0) data.insert_after(data.before_begin(), value);
    else {
        auto it = data.begin();
        for(int i = 0; i < getSize() - 1; i++) it++;
        data.insert_after(it, value);
    }   
}

int LinkedList::popBack() {
    if (getSize() < 1) outOfRange();
    if (getSize() == 1) {
        auto val = *data.begin();
        data.erase_after(data.before_begin());
        return val;
    } else {
        auto it = data.begin();
        auto prev = data.before_begin();
        for(int i = 0; i < getSize() - 1; i++, prev++) it++;
        auto val = *it;
        data.erase_after(prev);
        return val;
    }
}

int LinkedList::front() {
    if (getSize() < 1) outOfRange();
    return data.front();
}

int LinkedList::back() {
    if (getSize() < 1) outOfRange();
    auto it = data.begin();
    for(int i = 0; i < getSize() - 1; i++) it++;
    return *it;
}

void LinkedList::insert(int index, int value) {
    if (index < 0 || index > getSize()) outOfRange();
    if (index == 0) pushFront(value);
    else {
        auto it = data.begin();
        for(int i = 0; i < index - 1; i++) it++;
        data.insert_after(it, value);
    }
}

int LinkedList::value_n_from_end(int n) {
    auto index = getSize() - n - 1;
    return valueAt(index);
}

void LinkedList::reverse() {
    data.reverse();
}

void LinkedList::removeValue(int value) {
    auto prev  = data.before_begin();
    for(auto it = data.begin(); it != data.end(); it++, prev++) {
        if (*it == value) {
            data.erase_after(prev);
            return;
        }
    }
}

void LinkedList::erase(int index) {
    if (index < 0 || index >= getSize()) outOfRange();
    if (index == 0) data.erase_after(data.before_begin());
    else {
        auto it = data.begin();
        for(int i = 0; i < index - 1; i++) it++;
        data.erase_after(it);
    }
}