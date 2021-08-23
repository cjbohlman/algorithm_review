#include "linked_list.h"

int main() {
    List *list = (List *) calloc(1, sizeof(List));
    List *blank = (List *) malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;
    blank->size = 0;
    blank->head = NULL;

    assert(size(list) == 0);
    assert(empty(list));
    assert(!valueAt(list, 0));
    assert(!valueAt(list, -1));
    assert(!valueAt(list, 1));
    printList(list);

    pushFront(list, 3);
    assert(size(list) == 1);
    assert(!empty(list));
    assert(valueAt(list, 0) == 3);
    assert(!valueAt(list, 1));
    printList(list);

    pushFront(list, 2);
    pushFront(list, 1);
    assert(size(list) == 3);
    assert(!empty(list));
    assert(valueAt(list, 0) == 1);
    assert(valueAt(list, 1) == 2);
    assert(valueAt(list, 2) == 3);
    assert(!valueAt(list, 3));
    printList(list);

    popFront(list);
    assert(size(list) == 2);
    assert(!empty(list));
    assert(valueAt(list, 0) == 2);
    assert(valueAt(list, 1) == 3);
    assert(!valueAt(list, 2));
    popFront(list);
    popFront(list);
    assert(size(list) == 0);
    assert(empty(list));
    assert(!valueAt(list, 0));
    popFront(list);
    printList(list);

    pushBack(list, 1);
    assert(size(list) == 1);
    assert(!empty(list));
    printList(list);
    assert(valueAt(list, 0) == 1);
    assert(!valueAt(list, 1));
    pushBack(list, 2);
    pushBack(list, 3);
    assert(size(list) == 3);
    assert(!empty(list));
    assert(valueAt(list, 0) == 1);
    assert(valueAt(list, 1) == 2);
    assert(valueAt(list, 2) == 3);
    assert(!valueAt(list, 3));
    printList(list);

    popBack(list);
    assert(size(list) == 2);
    assert(!empty(list));
    assert(valueAt(list, 0) == 1);
    assert(valueAt(list, 1) == 2);
    assert(!valueAt(list, 2));
    popBack(list);
    popBack(list);
    printList(list);
    assert(size(list) == 0);
    assert(empty(list));
    assert(!valueAt(list, 0));
    popBack(list);
    printList(list);

    assert(!front(list));
    assert(!back(list));
    pushBack(list, 1);
    assert(front(list) == 1);
    assert(back(list) == 1);  
    pushBack(list, 2);
    pushFront(list, -1);
    assert(front(list) == -1);
    assert(back(list) == 2);  
    printList(list);

    insert(list, 1, 0);
    assert(size(list) == 4);
    assert(valueAt(list, 0) == -1);
    assert(valueAt(list, 1) == 0);
    assert(valueAt(list, 2) == 1);
    insert(list, 0, -2);
    assert(size(list) == 5);
    assert(valueAt(list, 0) == -2);
    assert(valueAt(list, 1) == -1);
    assert(valueAt(list, 2) == 0);
    insert(list, 0, -3);
    assert(size(list) == 6);
    assert(valueAt(list, 0) == -3);
    assert(valueAt(list, 1) == -2);
    assert(valueAt(list, 2) == -1);
    insert(list, 6, 3);
    assert(size(list) == 7);
    assert(valueAt(list, 4) == 1);
    assert(valueAt(list, 5) == 2);
    assert(valueAt(list, 6) == 3);
    insert(list, 10, 10);
    assert(size(list) == 7);
    insert(list, -1, 10);
    assert(size(list) == 7);
    printList(list);

    erase(list, 0);  
    printList(list);  
    assert(size(list) == 6);
    assert(valueAt(list, 0) == -2);
    erase(list, 1);
    printList(list);
    assert(size(list) == 5);
    assert(valueAt(list, 0) == -2);
    assert(valueAt(list, 1) == 0);
    erase(list, 3);
    assert(size(list) == 4);
    assert(valueAt(list, 0) == -2);
    assert(valueAt(list, 1) == 0);
    assert(valueAt(list, 2) == 1);
    assert(valueAt(list, 3) == 3);
    assert(!valueAt(list, 4));
    erase(list, 3);
    assert(size(list) == 3);
    assert(valueAt(list, 0) == -2);
    assert(valueAt(list, 1) == 0);
    assert(valueAt(list, 2) == 1);
    assert(!valueAt(list, 3));
    printList(list);

    assert(!value_n_from_end(list, -1));
    assert(value_n_from_end(list, 0) == 1);
    assert(value_n_from_end(list, 1) == 0);
    assert(value_n_from_end(list, 2) == -2);
    assert(!value_n_from_end(list, 3));
    printList(list);

    reverse(list);
    assert(!value_n_from_end(list, -1));
    assert(value_n_from_end(list, 2) == 1);
    assert(value_n_from_end(list, 1) == 0);
    assert(value_n_from_end(list, 0) == -2);
    assert(!value_n_from_end(list, 3));
    assert(!valueAt(list, -1));
    assert(valueAt(list, 0) == 1);
    assert(valueAt(list, 1) == 0);
    assert(valueAt(list, 2) == -2);
    assert(!valueAt(list, 3));
    printList(list);

    pushBack(list, -3);
    assert(size(list) == 4);
    remove_value(list,-8);
    assert(size(list) == 4);
    remove_value(list,-2);
    assert(size(list) == 3);
    assert(valueAt(list, 0) == 1);
    assert(valueAt(list, 1) == 0);
    assert(valueAt(list, 2) == -3);
    remove_value(list,-3);
    assert(size(list) == 2);
    assert(valueAt(list, 0) == 1);
    assert(valueAt(list, 1) == 0);
    remove_value(list,1);
    assert(size(list) == 1);
    assert(valueAt(list, 0) == 0);
    remove_value(list,0);
    assert(size(list) == 0);

    remove_value(blank, 2);
    reverse(blank);
    assert(!value_n_from_end(blank, 0));
    erase(blank, 0);
    erase(blank, 1);

    freeList(list);

    free(list);
    free(blank);
}