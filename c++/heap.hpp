#include<cassert>
#include<cmath>
#include<iostream>
#include<vector>
#include<stdexcept>

class Heap 
{
private:
    std::vector<int> arr;
    unsigned int size;

    int parent(int);
    int left(int);
    int right(int);

public:
    Heap();
    Heap(std::vector<int>);
    void insert(int);
    void sift_up(int);
    int extract_max();
    void max_heapify(int);
    int get_size();
    bool is_empty();
    void remove(int);
    void build_max_heap();
    void heap_sort();
    std::vector<int> get_arr();
    void print_heap();
};

Heap::Heap() {
    arr = std::vector<int>(101);
    size = 0;
}

Heap::Heap(std::vector<int> elements) {
    arr = std::vector<int>(101);
    unsigned int i;
    for(i = 0; i < elements.size(); i++) {
        arr.at(i + 1) = elements.at(i);
    }
    size = i;
}

int Heap::get_size() {
    return size;
}

bool Heap::is_empty() {
    return size == 0;
}

void Heap::insert(int value) {
    if (size == 100) return;
    auto newIndex = size + 1;
    arr.at(newIndex) = value;
    size++;
    sift_up(newIndex);
}

int Heap::extract_max() {
    if (size == 0) throw std::out_of_range("Extracting from empty heap");
    auto retVal = arr.at(1);
    arr.at(1) = arr.at(size);
    size--;
    max_heapify(1);
    return retVal;
}

void Heap::sift_up(int index) {
    while(arr.at(parent(index)) < arr.at(index)) {
        auto temp = arr.at(parent(index));
        arr.at(parent(index)) = arr.at(index);
        arr.at(index) = temp;
        index = parent(index);
    }
}

void Heap::max_heapify(int index) {
    unsigned int left_val = left(index);
    unsigned int right_val = right(index);
    auto largest = index;

    if (left_val <= size && arr.at(left_val) > arr.at(largest)) {
        largest = left_val;
    }

    if (right_val <= size && arr.at(right_val) > arr.at(largest)) {
        largest = right_val;
    }

    if (largest != index) {
        auto temp = arr.at(index);
        arr.at(index) = arr.at(largest);
        arr.at(largest) = temp;
        max_heapify(largest);
    }
}

int Heap::left(int index) {
    return 2 * index;
}

int Heap::right(int index) {
    return 2 * index + 1;
}

int Heap::parent(int index) {
    if (index == 1) return 1;
    else return floor(index/2);
}

void Heap::remove(int index) {
    arr.at(index) = arr.at(size);
    size--;
    max_heapify(index);
}

void Heap::build_max_heap() {
    for(auto i = floor(size/2); i >= 1; i--) {
        max_heapify(i);
    }
}

void Heap::heap_sort() {
    build_max_heap();
    int end = size;
    while(size > 1) {
        auto temp = arr.at(1);
        arr.at(1) = arr.at(end);
        arr.at(end) = temp;
        end--;
        size--;
        max_heapify(1);
    }
}

std::vector<int> Heap::get_arr() {
    return arr;
}

void Heap::print_heap() {
    std::cout << "Printing heap:" << std::endl;
    for (unsigned int i = 1; i <= size; i++) {
        std::cout << arr.at(i) << std::endl;
    }
    std::cout << "--------------" << std::endl;
}