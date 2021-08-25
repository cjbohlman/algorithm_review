#include "linked_list.hpp"

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
    list.printList();

    list.pushFront(3);
    assert(list.getSize() == 1);
    assert(!list.isEmpty());
    assert(list.valueAt(0) == 3);
    try {
        assert(list.valueAt(1));
        assert(1==0);
    } catch(...) {}
    list.printList();

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
    list.printList();

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
    list.printList();

    list.pushBack(1);
    assert(list.getSize() == 1);
    assert(!list.isEmpty());
    list.printList();
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
    list.printList();

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
    list.printList();
    assert(list.getSize() == 0);
    assert(list.isEmpty());
    try {
        assert(!list.valueAt(0));
        assert(1 == 0);
    } catch(...) {}
    list.printList();
    try {
        assert(list.popBack());
        assert(1 == 0);
    } catch(...) {}
    list.printList();

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
    list.printList();

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
    } catch(...) {}
    assert(list.getSize() == 7);
    try {
        list.insert(-1, 10);
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