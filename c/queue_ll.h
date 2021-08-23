#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int val;
    struct Node *next;
};

typedef struct Node Node;

struct Queue {
    Node *head;
    Node *tail;
};

typedef struct Queue Queue;

int empty(Queue *queue)
{
    return queue->head == NULL && queue->tail == NULL;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;

    if (empty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = queue->tail->next;
    }
}

int dequeue(Queue *queue) {
    if (empty(queue)) return NULL;
    int value = queue->head->val;
    Node *toFree = queue->head;
    queue->head = queue->head->next;
    free(toFree);
    if (NULL == queue->head) {
        queue->tail = NULL;
    }
    return value;
}

void print_queue(Queue *queue) {
    printf("Printing queue:\n");
    Node *qp = queue->head;
    while (NULL != qp) {
        printf("%d\n", qp->val);
        qp = qp->next;
    }
}