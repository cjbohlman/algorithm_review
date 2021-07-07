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

int main() {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->size = 0;
    assert(is_empty(heap));
    assert(0 == get_size(heap));

    // test insertion and subsequent max heap
    insert(heap, 1);
    insert(heap, 2);
    insert(heap, 3);
    insert(heap, 4);
    insert(heap, 5);
    insert(heap, 6);
    insert(heap, 7);

    assert(!is_empty(heap));
    assert(7 == get_size(heap));
    print_heap(heap);

    assert(7 == extract_max(heap));
    assert(6 == get_size(heap));
    assert(6 == extract_max(heap));
    assert(5 == get_size(heap));
    assert(5 == extract_max(heap));
    assert(4 == get_size(heap));
    assert(4 == extract_max(heap));
    assert(3 == get_size(heap));
    assert(3 == extract_max(heap));
    assert(2 == get_size(heap));
    assert(2 == extract_max(heap));
    assert(1 == get_size(heap));
    assert(1 == extract_max(heap));
    assert(0 == get_size(heap));
    assert(is_empty(heap));

    insert(heap, 1);
    insert(heap, 2);
    insert(heap, 3);
    insert(heap, 4);
    insert(heap, 5);
    insert(heap, 6);
    insert(heap, 7);
    print_heap(heap);

    remove_value(heap, 4);
    print_heap(heap);
    remove_value(heap, 7);
    print_heap(heap);
    remove_value(heap, 1);
    print_heap(heap);

    free(heap);

    // test build max heap on already created array
    Heap *heap2 = (Heap *) malloc(sizeof(Heap));
    int i;
    for (i = 100; i >= 1; i--) {
        heap2->arr[i] = i;
    }
    heap2->size = 100;
    assert(!is_empty(heap2));
    assert(100 == get_size(heap2));
    build_max_heap(heap2);
    print_heap(heap2);
    assert(100 == extract_max(heap2));
    assert(99 == extract_max(heap2));
    assert(98 == extract_max(heap2));
    assert(97 == extract_max(heap2));
    assert(96 == extract_max(heap2));
    assert(95 == extract_max(heap2));
    assert(94 == extract_max(heap2));
    assert(93 == extract_max(heap2));
    assert(92 == extract_max(heap2));
    assert(91 == extract_max(heap2));
    assert(90 == extract_max(heap2));
    assert(89 == extract_max(heap2));
    assert(88 == extract_max(heap2));
    assert(87 == extract_max(heap2));
    assert(86 == extract_max(heap2));
    assert(85 == extract_max(heap2));
    assert(84 == extract_max(heap2));
    assert(83 == extract_max(heap2));
    assert(82 == extract_max(heap2));
    assert(81 == extract_max(heap2));
    assert(80 == extract_max(heap2));
    assert(79 == extract_max(heap2));
    assert(78 == extract_max(heap2));
    assert(77 == extract_max(heap2));
    assert(76 == extract_max(heap2));
    assert(75 == extract_max(heap2));
    assert(74 == extract_max(heap2));
    assert(73 == extract_max(heap2));
    assert(72 == extract_max(heap2));
    assert(71 == extract_max(heap2));
    assert(70 == extract_max(heap2));
    assert(69 == extract_max(heap2));
    assert(68 == extract_max(heap2));
    assert(67 == extract_max(heap2));
    assert(66 == extract_max(heap2));
    assert(65 == extract_max(heap2));
    assert(64 == extract_max(heap2));
    assert(63 == extract_max(heap2));
    assert(62 == extract_max(heap2));
    assert(61 == extract_max(heap2));
    assert(60 == extract_max(heap2));
    assert(59 == extract_max(heap2));
    assert(58 == extract_max(heap2));
    assert(57 == extract_max(heap2));
    assert(56 == extract_max(heap2));
    assert(55 == extract_max(heap2));
    assert(54 == extract_max(heap2));
    assert(53 == extract_max(heap2));
    assert(52 == extract_max(heap2));
    assert(51 == extract_max(heap2));
    assert(50 == extract_max(heap2));
    assert(49 == extract_max(heap2));
    assert(48 == extract_max(heap2));
    assert(47 == extract_max(heap2));
    assert(46 == extract_max(heap2));
    assert(45 == extract_max(heap2));
    assert(44 == extract_max(heap2));
    assert(43 == extract_max(heap2));
    assert(42 == extract_max(heap2));
    assert(41 == extract_max(heap2));
    assert(40 == extract_max(heap2));
    assert(39 == extract_max(heap2));
    assert(38 == extract_max(heap2));
    assert(37 == extract_max(heap2));
    assert(36 == extract_max(heap2));
    assert(35 == extract_max(heap2));
    assert(34 == extract_max(heap2));
    assert(33 == extract_max(heap2));
    assert(32 == extract_max(heap2));
    assert(31 == extract_max(heap2));
    assert(30 == extract_max(heap2));
    assert(29 == extract_max(heap2));
    assert(28 == extract_max(heap2));
    assert(27 == extract_max(heap2));
    assert(26 == extract_max(heap2));
    assert(25 == extract_max(heap2));
    assert(24 == extract_max(heap2));
    assert(23 == extract_max(heap2));
    assert(22 == extract_max(heap2));
    assert(21 == extract_max(heap2));
    assert(20 == extract_max(heap2));
    assert(19 == extract_max(heap2));
    assert(18 == extract_max(heap2));
    assert(17 == extract_max(heap2));
    assert(16 == extract_max(heap2));
    print_heap(heap2);
    assert(15 == extract_max(heap2));
    assert(14 == extract_max(heap2));
    assert(13 == extract_max(heap2));
    assert(12 == extract_max(heap2));
    assert(11 == extract_max(heap2));
    assert(10 == extract_max(heap2));
    assert(9 == extract_max(heap2));
    assert(8 == extract_max(heap2));
    assert(7 == extract_max(heap2));
    assert(6 == extract_max(heap2));
    assert(5 == extract_max(heap2));
    assert(4 == extract_max(heap2));
    assert(3 == extract_max(heap2));
    assert(2 == extract_max(heap2));
    assert(1 == extract_max(heap2));
    
    free(heap2);   
    
    // test heapsort on already created array
    Heap *heap3 = (Heap *) malloc(sizeof(Heap));
    for (i = 100; i >= 1; i--) {
        heap3->arr[i] = i;
    }
    heap3->size = 100;
    assert(!is_empty(heap3));

    heap_sort(heap3);
    printf("Printing sorted array:\n");
    for (i = 1; i <= 100; i++) {
        printf("%d\n", heap3->arr[i]);
    }
    printf("----------------------\n");
    for (i = 1; i <= 100; i++) {
        assert(i == heap3->arr[i]);
    }
    free(heap3);
}