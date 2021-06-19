#include <stdexcept>
#include <memory>
#include <cassert>
#include <iostream>

class LinkedList{
private:
    class ListNode
    {
    public:
        int val;
        std::shared_ptr<ListNode> next;
        ListNode(int);
        ListNode(int, std::shared_ptr<ListNode>);
    };



    std::shared_ptr<ListNode> head;
    int size;

    void outOfRange();
public:
    LinkedList();
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


LinkedList::ListNode::ListNode(int value) {
    val = value;
    next = nullptr;
}

LinkedList::ListNode::ListNode(int value, std::shared_ptr<ListNode> next) {
    val = value;
    this->next = std::move(next);
}

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

int LinkedList::getSize() {
    return size;
}

bool LinkedList::isEmpty() {
    return getSize()==0;
}

void LinkedList::printList() {
    std::cout << "Printing LL of size: " << getSize() << std::endl;
    auto lp = head;
    while (lp != nullptr) {
        std::cout << lp->val << std::endl;
        lp = lp->next;
    }
}

int LinkedList::valueAt(int index) {
    if (index < 0 || index >= size) outOfRange();
    auto lp = head;
    int itr = 0;
    while (itr < index) {
        itr++;
        lp = lp->next;
    }
    return lp->val;
}

void LinkedList::pushFront(int value) {
    head = std::make_shared<ListNode>(ListNode{value, head});    
    size++;
}

int LinkedList::popFront()
{
    if (head == nullptr) outOfRange();
    auto data = head->val;
    head = head->next;
    size--;
    return data;
}

void LinkedList::pushBack(int value) {
    if (nullptr == head) {
        head = std::make_shared<ListNode>(ListNode{value});    
        size++;
    } else {
        auto lp = head;
        while (lp->next != nullptr) {
            lp = lp->next;
        }
        lp->next = std::make_shared<ListNode>(ListNode{value});    
        size++;
    }
}

int LinkedList::popBack() {
    if (nullptr == head) outOfRange();
    if (size == 1) {
        auto data = head->val;
        head = nullptr;
        size--;
        return data;
    }
    auto lp = head;
    auto prev = head;
    while (lp->next != nullptr) {
        prev = lp;
        lp = lp->next;
    }
    prev->next = nullptr;
    size--;
    return lp->val;
}

int LinkedList::front() {
    if (nullptr == head) outOfRange();
    return head->val;
}

int LinkedList::back() {
    if (nullptr == head) outOfRange();
    auto lp = head;
    while (lp->next != nullptr) {
        lp = lp->next;
    }
    return lp->val;
}

void LinkedList::insert(int index, int value) {
    if (index < 0 || index > size) outOfRange();
    if (index == 0) {
        pushFront(value);
    } else {
        auto lp = head->next;
        auto prev = head;
        auto itr = 1;
        while (itr < index) {
            prev = lp;
            lp = lp->next;
            itr++;
        }
        ListNode node{value, lp};
        prev->next = std::make_shared<ListNode>(node);
        size++;
    }
}

int LinkedList::value_n_from_end(int n) {
    auto index = size - n - 1;
    return valueAt(index);
}

void LinkedList::reverse() {
    std::shared_ptr<ListNode> prev = nullptr;
    auto cur = head;
    std::shared_ptr<ListNode> next = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

void LinkedList::removeValue(int value) {
    auto itr = 0;
    auto lp = head;
    while (lp != nullptr) {
        if (lp->val == value) {
            erase(itr);
            return;
        } else {
            lp = lp->next;
            itr++;
        }
    }
}

void LinkedList::erase(int index) {
    if (index < 0 || index >= size) outOfRange();
    if (index == 0) {
        size--;
        head = head->next;
    } else {
        auto prev = head;
        auto itr = 0;
        while (itr < index - 1) {
            itr++;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        size--;
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