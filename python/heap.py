import math

class Heap:
    def __init__(self, new_arr = None):
        self.arr = [None]*101
        if new_arr:
            index = 1
            for i in new_arr:
                self.arr[index] = i
                index += 1
            self.size = index - 1
        else:
            self.size = 0
       

    def insert(self, value):
        if self.size == 100:
            return
        self.size += 1
        self.arr[self.size] = value
        self.sift_up(self.size)

    def sift_up(self, index):
        while self.arr[self.parent(index)] < self.arr[index]:
            temp = self.arr[index]
            self.arr[index] = self.arr[self.parent(index)]
            self.arr[self.parent(index)] = temp
            index = self.parent(index)
    
    def max_heapify(self, index):
        left = self.left(index)
        right = self.right(index)
        largest = index

        if left <= self.size and self.arr[left] > self.arr[largest]:
            largest = left

        if right <= self.size and self.arr[right] > self.arr[largest]:
            largest = right

        if largest != index:
            temp = self.arr[index]
            self.arr[index] = self.arr[largest]
            self.arr[largest] = temp
            self.max_heapify(largest)

    def extract_max(self):
        if self.size == 0:
            raise Exception("Cannot extract from an empty heap")
        retVal = self.arr[1]
        self.size -= 1
        if self.size > 0:
            self.arr[1] = self.arr[self.size + 1]
            self.max_heapify(1)
        return retVal

    def parent(self, index):
        if index == 1:
            return 1
        else:
            return math.floor(index/2)

    def left(self, index):
        return 2 * index

    def right(self, index):
        return 2 * index + 1

    def get_size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def remove(self, index):
        self.arr[index] = self.arr[self.size]
        self.size -= 1
        self.max_heapify(index)

    def build_max_heap(self):
        for i in range(math.floor(self.size/2), 0):
            self.max_heapify(i)

    def heap_sort(self):
        self.build_max_heap()
        end = self.size
        while end > 1:
            temp = self.arr[1]
            self.arr[1] = self.arr[end]
            self.arr[end] = temp
            end -= 1
            self.size -= 1
            self.max_heapify(1)

    def print_heap(self):
        print("Printing heap:")
        for i in range(1, self.size + 1):
            if i is not None:
                print(self.arr[i])
        print("----------------------")

    def get_arr(self):
        return self.arr

def main():
    heap = Heap()
    assert heap.is_empty()
    assert 0 == heap.get_size()

    # test insertion and subsequent max heap
    heap.insert(1)
    heap.insert(2)
    heap.insert(3)
    heap.insert(4)
    heap.insert(5)
    heap.insert(6)
    heap.insert(7)

    assert not heap.is_empty()
    assert 7 == heap.get_size()
    heap.print_heap()

    assert 7 == heap.extract_max()
    assert 6 == heap.get_size()
    assert 6 == heap.extract_max()
    assert 5 == heap.get_size()
    assert 5 == heap.extract_max()
    assert 4 == heap.get_size()
    assert 4 == heap.extract_max()
    assert 3 == heap.get_size()
    assert 3 == heap.extract_max()
    assert 2 == heap.get_size()
    assert 2 == heap.extract_max()
    assert 1 == heap.get_size()
    assert 1 == heap.extract_max()
    assert 0 == heap.get_size()
    assert heap.is_empty()

    heap.insert(1)
    heap.insert(2)
    heap.insert(3)
    heap.insert(4)
    heap.insert(5)
    heap.insert(6)
    heap.insert(7)
    heap.print_heap()

    heap.remove(4)
    heap.print_heap()
    heap.remove(7)
    heap.print_heap()
    heap.remove(1)
    heap.print_heap()

    # test build max heap on already created array
    newArr = []
    for i in range(100, 0, -1):
        newArr.append(i)
    
    heap2 = Heap(newArr)
    heap2.print_heap()

    assert not heap2.is_empty()
    assert 100 == heap2.get_size()
    heap2.build_max_heap()
    heap2.print_heap()
    assert 100 == heap2.extract_max()
    assert 99 == heap2.extract_max()
    assert 98 == heap2.extract_max()
    assert 97 == heap2.extract_max()
    assert 96 == heap2.extract_max()
    assert 95 == heap2.extract_max()
    assert 94 == heap2.extract_max()
    assert 93 == heap2.extract_max()
    assert 92 == heap2.extract_max()
    assert 91 == heap2.extract_max()
    assert 90 == heap2.extract_max()
    assert 89 == heap2.extract_max()
    assert 88 == heap2.extract_max()
    assert 87 == heap2.extract_max()
    assert 86 == heap2.extract_max()
    assert 85 == heap2.extract_max()
    assert 84 == heap2.extract_max()
    assert 83 == heap2.extract_max()
    assert 82 == heap2.extract_max()
    assert 81 == heap2.extract_max()
    assert 80 == heap2.extract_max()
    assert 79 == heap2.extract_max()
    assert 78 == heap2.extract_max()
    assert 77 == heap2.extract_max()
    assert 76 == heap2.extract_max()
    assert 75 == heap2.extract_max()
    assert 74 == heap2.extract_max()
    assert 73 == heap2.extract_max()
    assert 72 == heap2.extract_max()
    assert 71 == heap2.extract_max()
    assert 70 == heap2.extract_max()
    assert 69 == heap2.extract_max()
    assert 68 == heap2.extract_max()
    assert 67 == heap2.extract_max()
    assert 66 == heap2.extract_max()
    assert 65 == heap2.extract_max()
    assert 64 == heap2.extract_max()
    assert 63 == heap2.extract_max()
    assert 62 == heap2.extract_max()
    assert 61 == heap2.extract_max()
    assert 60 == heap2.extract_max()
    assert 59 == heap2.extract_max()
    assert 58 == heap2.extract_max()
    assert 57 == heap2.extract_max()
    assert 56 == heap2.extract_max()
    assert 55 == heap2.extract_max()
    assert 54 == heap2.extract_max()
    assert 53 == heap2.extract_max()
    assert 52 == heap2.extract_max()
    assert 51 == heap2.extract_max()
    assert 50 == heap2.extract_max()
    assert 49 == heap2.extract_max()
    assert 48 == heap2.extract_max()
    assert 47 == heap2.extract_max()
    assert 46 == heap2.extract_max()
    assert 45 == heap2.extract_max()
    assert 44 == heap2.extract_max()
    assert 43 == heap2.extract_max()
    assert 42 == heap2.extract_max()
    assert 41 == heap2.extract_max()
    assert 40 == heap2.extract_max()
    assert 39 == heap2.extract_max()
    assert 38 == heap2.extract_max()
    assert 37 == heap2.extract_max()
    assert 36 == heap2.extract_max()
    assert 35 == heap2.extract_max()
    assert 34 == heap2.extract_max()
    assert 33 == heap2.extract_max()
    assert 32 == heap2.extract_max()
    assert 31 == heap2.extract_max()
    assert 30 == heap2.extract_max()
    assert 29 == heap2.extract_max()
    assert 28 == heap2.extract_max()
    assert 27 == heap2.extract_max()
    assert 26 == heap2.extract_max()
    assert 25 == heap2.extract_max()
    assert 24 == heap2.extract_max()
    assert 23 == heap2.extract_max()
    assert 22 == heap2.extract_max()
    assert 21 == heap2.extract_max()
    assert 20 == heap2.extract_max()
    assert 19 == heap2.extract_max()
    assert 18 == heap2.extract_max()
    assert 17 == heap2.extract_max()
    assert 16 == heap2.extract_max()
    heap2.print_heap()
    assert 15 == heap2.extract_max()
    assert 14 == heap2.extract_max()
    assert 13 == heap2.extract_max()
    assert 12 == heap2.extract_max()
    assert 11 == heap2.extract_max()
    assert 10 == heap2.extract_max()
    assert 9 == heap2.extract_max()
    assert 8 == heap2.extract_max()
    assert 7 == heap2.extract_max()
    assert 6 == heap2.extract_max()
    assert 5 == heap2.extract_max()
    assert 4 == heap2.extract_max()
    heap2.print_heap()
    assert 3 == heap2.extract_max()
    assert 2 == heap2.extract_max()
    assert 1 == heap2.extract_max()
        
    # test heapsort on already created array
    newArr2 = []
    for i in range(100, 0, -1):
        newArr2.append(i)
    
    heap3 = Heap(newArr2)
    assert not heap3.is_empty()

    heap3.heap_sort()
    vec = heap3.get_arr()
    print("Printing sorted array:")
    for i in vec:
        if i is not None:
            print(i)
    print("----------------------")
    for i in range(1, 101):
        assert i == vec[i]

if __name__ == "__main__":
    main()