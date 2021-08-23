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