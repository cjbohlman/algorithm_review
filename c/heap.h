// max heap impl

#include<assert.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>

struct Heap {
    int arr[101]; // max 100 elements, starting at 1
    int size;
};

typedef struct Heap Heap;

int is_empty(Heap *heap) {
    return heap->size == 0;
}

int get_size(Heap *heap) {
    return heap->size;
}

int parent(int index) {
    if (index == 1) return 1;
    else return floor(index/2);
}

int left(int index) {
    return index * 2;
}

int right(int index) {
    return index * 2 + 1;
}

void print_heap(Heap *heap) {
    printf("Printing heap:\n");
    int i;
    for (i = 1; i <= heap->size; i++) {
        printf("%d\n", heap->arr[i]);
    }
    printf("--------------\n");
}

void sift_up(Heap *heap, int index) {
    while(heap->arr[parent(index)] < heap->arr[index]) {
        int temp = heap->arr[parent(index)];
        heap->arr[parent(index)] = heap->arr[index];
        heap->arr[index] = temp;
        index = parent(index);
    }
}

void insert(Heap *heap, int value) {
    if (heap->size == 100) return;
    int newIndex = 1+heap->size;
    heap->arr[newIndex] = value;
    heap->size++;
    sift_up(heap, newIndex);
}

void max_heapify(Heap *heap, int index) {
    int left_index = left(index);
    int right_index = right(index);

    int largest = index;

    if (left_index <= heap->size && heap->arr[left_index] > heap->arr[largest])
        largest = left_index;

    if (right_index <= heap->size && heap->arr[right_index] > heap->arr[largest])
        largest = right_index;

    if (largest != index) {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;
        max_heapify(heap, largest);
    }
}

int extract_max(Heap *heap) {
    int retVal = heap->arr[1];
    if (heap->size > 1) {
        heap->arr[1] = heap->arr[heap->size];
        max_heapify(heap, 1);
    }
    heap->size -= 1;
    return retVal;
}

void remove_value(Heap *heap, int index) {
    // int temp = heap->arr[index];
    heap->arr[index] = heap->arr[heap->size];
    heap->size--;
    max_heapify(heap, index);
}

void build_max_heap(Heap *heap) {
    int i;
    for(i = floor(heap->size/2); i >=1; i--) {
        max_heapify(heap, i);
    }
}

void heap_sort(Heap *heap) {
    build_max_heap(heap);
    int end = heap->size;

    while (end > 1) {
        int temp = heap->arr[1];
        heap->arr[1] = heap->arr[end];
        heap->arr[end] = temp;
        end--;
        heap->size--;
        max_heapify(heap, 1);
    }
}