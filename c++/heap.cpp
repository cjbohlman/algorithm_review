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

int main() {
    Heap heap{};
    assert(heap.is_empty());
    assert(0 == heap.get_size());

    // test insertion and subsequent max heap
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);

    assert(!heap.is_empty());
    assert(7 == heap.get_size());
    heap.print_heap();

    assert(7 == heap.extract_max());
    assert(6 == heap.get_size());
    assert(6 == heap.extract_max());
    assert(5 == heap.get_size());
    assert(5 == heap.extract_max());
    assert(4 == heap.get_size());
    assert(4 == heap.extract_max());
    assert(3 == heap.get_size());
    assert(3 == heap.extract_max());
    assert(2 == heap.get_size());
    assert(2 == heap.extract_max());
    assert(1 == heap.get_size());
    assert(1 == heap.extract_max());
    assert(0 == heap.get_size());
    assert(heap.is_empty());

    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);
    heap.print_heap();

    heap.remove(4);
    heap.print_heap();
    heap.remove(7);
    heap.print_heap();
    heap.remove(1);
    heap.print_heap();

    // test build max heap on already created array
    std::vector<int> newArr;
    int i;
    for (i = 100; i >= 1; i--) {
        newArr.push_back(i);
    }
    Heap heap2{newArr};

    assert(!heap2.is_empty());
    assert(100 == heap2.get_size());
    heap2.build_max_heap();
    heap2.print_heap();
    assert(100 == heap2.extract_max());
    assert(99 == heap2.extract_max());
    assert(98 == heap2.extract_max());
    assert(97 == heap2.extract_max());
    assert(96 == heap2.extract_max());
    assert(95 == heap2.extract_max());
    assert(94 == heap2.extract_max());
    assert(93 == heap2.extract_max());
    assert(92 == heap2.extract_max());
    assert(91 == heap2.extract_max());
    assert(90 == heap2.extract_max());
    assert(89 == heap2.extract_max());
    assert(88 == heap2.extract_max());
    assert(87 == heap2.extract_max());
    assert(86 == heap2.extract_max());
    assert(85 == heap2.extract_max());
    assert(84 == heap2.extract_max());
    assert(83 == heap2.extract_max());
    assert(82 == heap2.extract_max());
    assert(81 == heap2.extract_max());
    assert(80 == heap2.extract_max());
    assert(79 == heap2.extract_max());
    assert(78 == heap2.extract_max());
    assert(77 == heap2.extract_max());
    assert(76 == heap2.extract_max());
    assert(75 == heap2.extract_max());
    assert(74 == heap2.extract_max());
    assert(73 == heap2.extract_max());
    assert(72 == heap2.extract_max());
    assert(71 == heap2.extract_max());
    assert(70 == heap2.extract_max());
    assert(69 == heap2.extract_max());
    assert(68 == heap2.extract_max());
    assert(67 == heap2.extract_max());
    assert(66 == heap2.extract_max());
    assert(65 == heap2.extract_max());
    assert(64 == heap2.extract_max());
    assert(63 == heap2.extract_max());
    assert(62 == heap2.extract_max());
    assert(61 == heap2.extract_max());
    assert(60 == heap2.extract_max());
    assert(59 == heap2.extract_max());
    assert(58 == heap2.extract_max());
    assert(57 == heap2.extract_max());
    assert(56 == heap2.extract_max());
    assert(55 == heap2.extract_max());
    assert(54 == heap2.extract_max());
    assert(53 == heap2.extract_max());
    assert(52 == heap2.extract_max());
    assert(51 == heap2.extract_max());
    assert(50 == heap2.extract_max());
    assert(49 == heap2.extract_max());
    assert(48 == heap2.extract_max());
    assert(47 == heap2.extract_max());
    assert(46 == heap2.extract_max());
    assert(45 == heap2.extract_max());
    assert(44 == heap2.extract_max());
    assert(43 == heap2.extract_max());
    assert(42 == heap2.extract_max());
    assert(41 == heap2.extract_max());
    assert(40 == heap2.extract_max());
    assert(39 == heap2.extract_max());
    assert(38 == heap2.extract_max());
    assert(37 == heap2.extract_max());
    assert(36 == heap2.extract_max());
    assert(35 == heap2.extract_max());
    assert(34 == heap2.extract_max());
    assert(33 == heap2.extract_max());
    assert(32 == heap2.extract_max());
    assert(31 == heap2.extract_max());
    assert(30 == heap2.extract_max());
    assert(29 == heap2.extract_max());
    assert(28 == heap2.extract_max());
    assert(27 == heap2.extract_max());
    assert(26 == heap2.extract_max());
    assert(25 == heap2.extract_max());
    assert(24 == heap2.extract_max());
    assert(23 == heap2.extract_max());
    assert(22 == heap2.extract_max());
    assert(21 == heap2.extract_max());
    assert(20 == heap2.extract_max());
    assert(19 == heap2.extract_max());
    assert(18 == heap2.extract_max());
    assert(17 == heap2.extract_max());
    assert(16 == heap2.extract_max());
    heap2.print_heap();
    assert(15 == heap2.extract_max());
    assert(14 == heap2.extract_max());
    assert(13 == heap2.extract_max());
    assert(12 == heap2.extract_max());
    assert(11 == heap2.extract_max());
    assert(10 == heap2.extract_max());
    assert(9 == heap2.extract_max());
    assert(8 == heap2.extract_max());
    assert(7 == heap2.extract_max());
    assert(6 == heap2.extract_max());
    assert(5 == heap2.extract_max());
    assert(4 == heap2.extract_max());
    assert(3 == heap2.extract_max());
    assert(2 == heap2.extract_max());
    assert(1 == heap2.extract_max());
        
    // test heapsort on already created array
    std::vector<int> newArr2;
    for (i = 100; i >= 1; i--) {
        newArr2.push_back(i);
    }
    Heap heap3{newArr2};
    assert(!heap3.is_empty());

    heap3.heap_sort();
    auto vec = heap3.get_arr();
    std::cout << "Printing sorted array:" << std::endl;
    for (i = 1; i <= 100; i++) {
        std::cout << vec.at(i) << std::endl;
    }
    std::cout << "----------------------" << std::endl;
    for (i = 1; i <= 100; i++) {
        assert(i == vec.at(i));
    }
}