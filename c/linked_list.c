#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct List {
    int size;
    ListNode *head;
};

typedef struct List List;

int size(List *list) {
    return list->size;
}

int empty(List *list) {
    return list->size == 0;
}

int valueAt(List *list, int index) {
    if (index >= list->size || index < 0) return NULL;
    int i;
    ListNode *lp = list->head;
    for(i=0; i < index; i++) {
        lp = lp->next;
    }
    return lp->val;
}

void pushFront(List *list, int element) {
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    if (NULL == newNode) {
        printf("alloc in pushFront failed");
    }
    newNode->val = element;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void printList(List *list) {
    ListNode *lp = list->head;
    printf("Printing out vec of size %d:\n", list->size);
    while (lp != NULL) {
        printf("%d\n", lp->val);
        lp = lp->next;
    }
}

void popFront(List *list) {
    if (NULL == list->head) return;
    ListNode *newHead = list->head->next;
    free(list->head);
    list->size--;
    list->head = newHead;
}

void pushBack(List *list, int element) 
{
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->val = element;
    newNode->next = NULL;
    if (NULL == newNode) {
        printf("alloc in pushBack failed");
    }
    if (NULL == list->head) {
        list->head = newNode;
    } else {
        ListNode *lp = list->head;
        while(NULL != lp->next) {
            lp = lp->next;
        }
        lp->next = newNode;
    }
    list->size++;
}

void popBack(List *list)
{
    if (NULL == list->head) return;
    if (1 == list->size) {
        free(list->head);
        list->head = NULL;
    } else {
        ListNode *lp = list->head;
        while (NULL != lp->next->next) {
            lp = lp->next;
        }
        free(lp->next);
        lp->next = NULL;
    }
    list->size--;
}

int front(List *list) 
{
    if (NULL == list->head) return NULL;
    return list->head->val;
}

int back(List *list)
{
    if (NULL == list->head) return NULL;
    ListNode *lp = list->head;
    while(NULL != lp->next) {
        lp = lp->next;
    }
    return lp->val;
}

void insert(List *list, int index, int value)
{
    if (index > list->size || index < 0) return;
    ListNode *newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->val = value;
    newNode->next = NULL;
    if (0 == index) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
    } else {
        int itr = 0;
        ListNode *lp = list->head;
        while(itr != index - 1) {
            lp = lp->next;
            itr++;
        }
        newNode->next = lp->next;
        lp->next = newNode;
        list->size++;
    }
}

void erase(List *list, int index)
{
    if (index >= list->size || index < 0) return;
    if (0 == index) {
        popFront(list);
    } else {
        // we want to land on the node before the index
        int itr = 0;
        ListNode *prev = list->head;
        while(itr < index - 1) {
            itr++;
            prev = prev->next;
        }
        ListNode *toDelete = prev->next;
        prev->next = toDelete->next;
        free(toDelete);
        list->size--;
    }

}


int value_n_from_end(List *list, int n)
{
    if (n >= list->size || n < 0) return NULL;
    int i = 0;
    ListNode *lp = list->head;
    for(i = 0; i < list->size - n - 1; i++) {
        lp = lp->next;
    }
    return lp->val;
}

void reverse(List *list)
{
    ListNode *prev = NULL, *cur = list->head, *next = NULL;
    while (NULL != cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    list->head = prev;
}

void remove_value(List *list,int value)
{
    if (NULL == list->head) return;
    if (list->head->val == value) {
        ListNode *lp = list->head;
        list->head = list->head->next;
        free(lp);
        list->size--;
    } else {
        ListNode *prev = list->head;
        ListNode *lp = list->head->next;
        while (lp != NULL && lp->val != value) {
            prev = lp;
            lp = lp->next;
        }
        if (NULL == lp) return;
        prev->next = lp->next;
        free(lp);
        list->size--;
    }
}

void freeList(List *list)
{
    ListNode *lp = list->head;
    ListNode *prev = NULL;

    while(NULL != lp) {
        prev = lp;
        lp = lp->next;
        free(prev);
    }
}

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