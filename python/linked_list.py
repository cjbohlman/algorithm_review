from collections import deque 

class LinkedList:
    def __init__(self):
        self.data = deque()

    def get_size(self):
        return len(self.data)

    def is_empty(self):
        return self.get_size() == 0

    def value_at(self, index):
        return self.data[index]

    def push_front(self, value):
        self.data.appendleft(value)

    def pop_front(self):
        return self.data.popleft()

    def push_back(self, value):
        self.data.append(value)

    def pop_back(self):
        return self.data.pop()

    def front(self):
        return self.data[0]

    def back(self):
        return self.data[self.get_size() - 1]
    
    def insert(self, index, value):
        if index < 0 or index > self.get_size():
            raise ValueError("out of range in insert")
        self.data.insert(index, value)

    def erase(self, index):
        del self.data[index]

    def value_n_from_end(self, n):
        return self.value_at(self.get_size() - n - 1)

    def reverse(self):
        self.data.reverse()

    def remove_value(self, value):
        for i in range(self.get_size()):
            if self.data[i] == value:
                del self.data[i]
                return

    def print_list(self):
        print("Printing out list of size " , self.get_size())
        for i in self.data:
            print(i)

def main():
    list = LinkedList()
    blank = LinkedList()

    assert list.get_size() == 0
    assert list.is_empty()
    try:
        list.value_at(0)
        assert 1==0
    except:
        pass 
    try:
        list.value_at(-1)
        assert 1==0
    except:
        pass
    try:
        list.value_at(1)
        assert 1==0
    except:
        pass
    list.print_list() # 1

    list.push_front(3)
    assert list.get_size() == 1
    assert not list.is_empty()
    assert list.value_at(0) == 3
    try:
        assert list.value_at(1)
        assert 1==0
    except:
        pass
    list.print_list() # 2

    list.push_front(2)
    list.push_front(1)
    assert list.get_size() == 3
    assert not list.is_empty()
    assert list.value_at(0) == 1
    assert list.value_at(1) == 2
    assert list.value_at(2) == 3
    try:
        assert list.value_at(3)
        assert 1==0
    except:
        pass
    list.print_list() # 3

    assert list.pop_front() == 1
    assert list.get_size() == 2
    assert not list.is_empty()
    assert list.value_at(0) == 2
    assert list.value_at(1) == 3
    try:
        assert list.value_at(2)
        assert 1 == 0
    except:
        pass
    assert list.pop_front() == 2
    assert list.pop_front() == 3
    assert list.get_size() == 0
    assert list.is_empty()
    try:
        assert list.value_at(0)
    except:
        pass
    try:
        list.pop_front()
        assert 1==0
    except:
        pass
    list.print_list() # 4

    list.push_back(1)
    assert list.get_size() == 1
    assert not list.is_empty()
    list.print_list() # 5
    assert list.value_at(0) == 1
    try: 
        assert list.value_at(1)
        assert 1==0
    except:
        pass
    list.push_back(2)
    list.push_back(3)
    assert list.get_size() == 3
    assert not list.is_empty()
    assert list.value_at(0) == 1
    assert list.value_at(1) == 2
    assert list.value_at(2) == 3
    try: 
        assert list.value_at(3)
        assert 1==0
    except:
        pass
    list.print_list()  # 6

    assert list.pop_back() == 3
    assert list.get_size() == 2
    assert not list.is_empty()
    assert list.value_at(0) == 1
    assert list.value_at(1) == 2
    try:
        assert list.value_at(2)
        assert 1==0
    except:
        pass
    assert list.pop_back() == 2
    assert list.pop_back() == 1
    list.print_list() # 7
    assert list.get_size() == 0
    assert list.is_empty()
    try:
        assert list.value_at(0)
        assert 1==0
    except:
        pass
    list.print_list() # 8
    try:
        assert list.pop_back()
        assert 1==0
    except:
        pass
    list.print_list() # 9

    try:
        assert list.front()
        assert 1==0
    except:
        pass
    try:
        assert list.back()
        assert 1==0
    except:
        pass
    list.push_back(1)
    assert list.front() == 1
    assert list.back() == 1
    list.push_back(2)
    list.push_front(-1)
    assert list.front() == -1
    assert list.back() == 2
    list.print_list() # 10

    list.insert(1, 0)
    list.print_list()
    assert list.get_size() == 4
    assert list.value_at(0) == -1
    assert list.value_at(1) == 0
    assert list.value_at(2) == 1
    list.insert(0, -2)
    assert list.get_size() == 5
    assert list.value_at(0) == -2
    assert list.value_at(1) == -1
    assert list.value_at(2) == 0
    list.insert(0, -3)
    assert list.get_size() == 6
    assert list.value_at(0) == -3
    assert list.value_at(1) == -2
    assert list.value_at(2) == -1
    list.insert(6, 3)
    assert list.get_size() == 7
    assert list.value_at(4) == 1
    assert list.value_at(5) == 2
    assert list.value_at(6) == 3
    try:
        list.insert(10, 10)
        assert 1 == 0
    except:
        pass
    assert list.get_size() == 7
    try:
        list.insert(-1, 10)
        assert 1 == 0
    except:
        pass
    assert list.get_size() == 7
    list.print_list()

    list.erase(0)  
    list.print_list()  
    assert list.get_size() == 6
    assert list.value_at(0) == -2
    list.erase(1)
    list.print_list()
    assert list.get_size() == 5
    assert list.value_at(0) == -2
    assert list.value_at(1) == 0
    list.erase(3)
    assert list.get_size() == 4
    assert list.value_at(0) == -2
    assert list.value_at(1) == 0
    assert list.value_at(2) == 1
    assert list.value_at(3) == 3
    try:
        assert list.value_at(4)
        assert 1==0
    except:
        pass
    list.erase(3)
    assert list.get_size() == 3
    assert list.value_at(0) == -2
    assert list.value_at(1) == 0
    assert list.value_at(2) == 1
    try:
        assert list.value_at(3)
        assert 1==0
    except:
        pass
    list.print_list()

    try:
        assert list.value_n_from_end(-1)
        assert 1==0
    except:
        pass
    assert list.value_n_from_end(0) == 1
    assert list.value_n_from_end(1) == 0
    assert list.value_n_from_end(2) == -2
    try:
        assert list.value_n_from_end(3)
        assert 1==0
    except:
        pass
    list.print_list()

    list.reverse()
    try:
        assert list.value_n_from_end(-1)
        assert 1==0
    except:
        pass
    list.print_list()
    assert list.value_n_from_end(2) == 1
    assert list.value_n_from_end(1) == 0
    assert list.value_n_from_end(0) == -2
    try:
        assert list.value_n_from_end(3)
        assert 1==0
    except:
        pass
    try:
        assert list.value_at(-1)
        assert 1== 0
    except:
        pass
    assert list.value_at(0) == 1
    assert list.value_at(1) == 0
    assert list.value_at(2) == -2
    try:
        assert list.value_at(3)
        assert 1 == 0
    except:
        pass
    list.print_list()

    list.push_back(-3)
    assert list.get_size() == 4
    list.remove_value(-8)
    assert list.get_size() == 4
    list.remove_value(-2)
    assert list.get_size() == 3
    assert list.value_at(0) == 1
    assert list.value_at(1) == 0
    assert list.value_at(2) == -3
    list.remove_value(-3)
    assert list.get_size() == 2
    assert list.value_at(0) == 1
    assert list.value_at(1) == 0
    list.remove_value(1)
    assert list.get_size() == 1
    assert list.value_at(0) == 0
    list.remove_value(0)
    assert list.get_size() == 0

    blank.remove_value(2)
    blank.reverse()
    try:
        assert blank.value_n_from_end(0) == 0
        assert 1==0
    except:
        pass
    try:
        blank.erase(0)
        assert 1==0
    except:
        pass
    try:
        blank.erase(1)
        assert 1==0
    except:
        pass
    return

if __name__ == "__main__":
    main()