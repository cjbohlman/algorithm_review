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

int main() {
    LinkedList list{};
    LinkedList blank{};

    assert(list.getSize() == 0);
    assert(list.isEmpty());
    try {
        list.valueAt( 0);
        assert(1==0);
    } catch (...) {}
    try {
        list.valueAt(-1);
        assert(1==0);
    } catch (...) {}
    try {
        list.valueAt(1);
        assert(1==0);
    } catch (...) {}
    list.printList(); // 1

    list.pushFront(3);
    assert(list.getSize() == 1);
    assert(!list.isEmpty());
    assert(list.valueAt(0) == 3);
    try {
        assert(list.valueAt(1));
        assert(1==0);
    } catch(...) {}
    list.printList(); // 2

    list.pushFront(2);
    list.pushFront(1);
    assert(list.getSize() == 3);
    assert(!list.isEmpty());
    assert(list.valueAt(0) == 1);
    assert(list.valueAt(1) == 2);
    assert(list.valueAt(2) == 3);
    try {
        assert(!list.valueAt(3));
        assert(1==0);
    } catch(...){}
    list.printList(); // 3

    assert(list.popFront() == 1);
    assert(list.getSize() == 2);
    assert(!list.isEmpty());
    assert(list.valueAt(0) == 2);
    assert(list.valueAt(1) == 3);
    try {
        assert(list.valueAt(2));
        assert(1 == 0);
    } catch(...) {}
    assert(list.popFront() == 2);
    assert(list.popFront() == 3);
    assert(list.getSize() == 0);
    assert(list.isEmpty());
    try {
        assert(!list.valueAt(0));
    } catch (...) {}
    try {
        list.popFront();
        assert(1 == 0);
    } catch (...) {}
    list.printList(); // 4

    list.pushBack(1);
    assert(list.getSize() == 1);
    assert(!list.isEmpty());
    list.printList(); // 5
    assert(list.valueAt(0) == 1);
    try { 
        assert(!list.valueAt(1));
        assert(1==0);
    } catch (...) {}
    list.pushBack(2);
    list.pushBack(3);
    assert(list.getSize() == 3);
    assert(!list.isEmpty());
    assert(list.valueAt(0) == 1);
    assert(list.valueAt(1) == 2);
    assert(list.valueAt(2) == 3);
    try { 
        assert(!list.valueAt(3));
        assert(1==0);
    } catch (...) {}
    list.printList();  // 6

    assert(list.popBack() == 3);
    assert(list.getSize() == 2);
    assert(!list.isEmpty());
    assert(list.valueAt(0) == 1);
    assert(list.valueAt(1) == 2);
    try {
        assert(!list.valueAt(2));
        assert(1 == 0);
    } catch(...) {}
    assert(list.popBack() == 2);
    assert(list.popBack() == 1);
    list.printList(); // 7
    assert(list.getSize() == 0);
    assert(list.isEmpty());
    try {
        assert(!list.valueAt(0));
        assert(1 == 0);
    } catch(...) {}
    list.printList(); // 8
    try {
        assert(list.popBack());
        assert(1 == 0);
    } catch(...) {}
    list.printList(); // 9

    try {
        assert(!list.front());
        assert(1 == 0);
    } catch(...) {}
    try {
        assert(!list.back());
        assert(1 == 0);
    } catch(...) {}
    list.pushBack(1);
    assert(list.front() == 1);     
    assert(list.back() == 1);  
    list.pushBack(2);
    list.pushFront(-1);
    assert(list.front() == -1);
    assert(list.back() == 2);  
    list.printList(); // 10

    list.insert(1, 0);
    list.printList();
    assert(list.getSize() == 4);
    assert(list.valueAt(0) == -1);
    assert(list.valueAt(1) == 0);
    assert(list.valueAt(2) == 1);
    list.insert(0, -2);
    assert(list.getSize() == 5);
    assert(list.valueAt(0) == -2);
    assert(list.valueAt(1) == -1);
    assert(list.valueAt(2) == 0);
    list.insert(0, -3);
    assert(list.getSize() == 6);
    assert(list.valueAt(0) == -3);
    assert(list.valueAt(1) == -2);
    assert(list.valueAt(2) == -1);
    list.insert(6, 3);
    assert(list.getSize() == 7);
    assert(list.valueAt(4) == 1);
    assert(list.valueAt(5) == 2);
    assert(list.valueAt(6) == 3);
    try {
        list.insert(10, 10);
        assert(1 == 0);
    } catch(...) {}
    assert(list.getSize() == 7);
    try {
        list.insert(-1, 10);
        assert(1 == 0);
    } catch (...) {}
    assert(list.getSize() == 7);
    list.printList();

    list.erase(0);  
    list.printList();  
    assert(list.getSize() == 6);
    assert(list.valueAt(0) == -2);
    list.erase(1);
    list.printList();
    assert(list.getSize() == 5);
    assert(list.valueAt(0) == -2);
    assert(list.valueAt(1) == 0);
    list.erase(3);
    assert(list.getSize() == 4);
    assert(list.valueAt(0) == -2);
    assert(list.valueAt(1) == 0);
    assert(list.valueAt(2) == 1);
    assert(list.valueAt(3) == 3);
    try {
        assert(!list.valueAt(4));
        assert(1 == 0);
    } catch(...) {}
    list.erase(3);
    assert(list.getSize() == 3);
    assert(list.valueAt(0) == -2);
    assert(list.valueAt(1) == 0);
    assert(list.valueAt(2) == 1);
    try {
        assert(!list.valueAt(3));
        assert(1 == 0);
    } catch(...) {}
    list.printList();

    try {
        assert(!list.value_n_from_end(-1));
        assert(1 == 0);
    } catch (...) {}
    assert(list.value_n_from_end(0) == 1);
    assert(list.value_n_from_end(1) == 0);
    assert(list.value_n_from_end(2) == -2);
    try {
        assert(!list.value_n_from_end(3));
        assert(1 == 0);
    } catch (...) {}
    list.printList();

    list.reverse();
    try {
        assert(!list.value_n_from_end(-1));
        assert(1 == 0);
    } catch (...) {}
    list.printList();
    assert(list.value_n_from_end(2) == 1);
    assert(list.value_n_from_end(1) == 0);
    assert(list.value_n_from_end(0) == -2);
    try {
        assert(!list.value_n_from_end(3));
        assert(1 == 0);
    } catch (...) {}
    try {
        assert(!list.valueAt(-1));
        assert(1== 0);
    } catch(...) {}
    assert(list.valueAt(0) == 1);
    assert(list.valueAt(1) == 0);
    assert(list.valueAt(2) == -2);
    try {
        assert(!list.valueAt(3));
        assert(1 == 0);
    } catch(...) {}
    list.printList();

    list.pushBack(-3);
    assert(list.getSize() == 4);
    list.removeValue(-8);
    assert(list.getSize() == 4);
    list.removeValue(-2);
    assert(list.getSize() == 3);
    assert(list.valueAt(0) == 1);
    assert(list.valueAt(1) == 0);
    assert(list.valueAt(2) == -3);
    list.removeValue(-3);
    assert(list.getSize() == 2);
    assert(list.valueAt(0) == 1);
    assert(list.valueAt(1) == 0);
    list.removeValue(1);
    assert(list.getSize() == 1);
    assert(list.valueAt(0) == 0);
    list.removeValue(0);
    assert(list.getSize() == 0);

    blank.removeValue(2);
    blank.reverse();
    try {
        assert(blank.value_n_from_end(0) == 0);
        assert(1 == 0);
    } catch(...) {}
    try {
        blank.erase(0);
        assert(1 == 0);
    } catch(...) {}
    try {
        blank.erase(1);
        assert(1 == 0);
    } catch(...) {}
}