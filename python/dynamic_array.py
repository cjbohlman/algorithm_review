class ChrisVec:
    def __init__(self):
        self.data = [None] * 16
        self.capacity = 16
        self.size = 0

    def check_resize_up(self):
        if self.get_size() + 1 == self.capacity:
            self.resize(self.capacity * 2)

    def check_resize_down(self):
        if self.get_size() - 1 <= self.capacity/4:
            self.resize(self.capacity/2)


    def get_capacity(self):
        return self.capacity

    def get_size(self):
        return self.size

    def is_empty(self):
        return self.get_size() == 0

    def at(self, index):
        return self.data[index]

    def push(self, element):
        self.check_resize_up()
        self.data[self.size] = element
        self.size += 1

    def insert(self, index, element):
        self.check_resize_up()
        self.data.insert(index, element)
        self.size += 1


    def prepend(self, element):
        self.insert(0, element)

    def pop(self):
        self.check_resize_down()
        self.data[self.get_size() - 1] = None
        self.size -= 1


    def delete(self, index):
        self.check_resize_down()
        for i in range(index, self.size):
            self.data[i] = self.data[i+1]
        self.size -= 1

    def remove(self, element):
        for i in range(self.get_size() - 1, -1, -1):
            if self.data[i] == element:
                self.delete(i)
    
    def find(self, element):
        try:
            index = self.data.index(element)
            return index
        except ValueError:
            return -1

    def resize(self, new_capacity):
        new_list = [None] * int(new_capacity)
        for i in range(self.get_size()):
            new_list[i] = self.data[i]
        self.data = new_list
        self.capacity = new_capacity

    def print_vec(self):
        print("printing vec")
        for i in self.data:
            if i != None:
                print(i)

def main():
    vec = ChrisVec()
    assert vec.is_empty()
    for i in range(6):
        vec.push(i)
    assert vec.get_size() == 6
    assert vec.get_capacity() == 16
    vec.print_vec()
    assert vec.at( 0) == 0
    assert vec.at( 1) == 1
    assert vec.at( 2) == 2
    assert vec.at( 3) == 3
    assert vec.at( 4) == 4
    assert vec.at( 5) == 5
    vec.pop()
    vec.pop()
    assert vec.get_size() == 4
    vec.print_vec()
    vec.prepend( -2)
    vec.print_vec()
    vec.insert( 1, -1)
    vec.print_vec()
    vec.delete( 2)
    vec.print_vec()
    assert vec.at( 0) == -2
    assert vec.at( 1) == -1
    print(vec.at(2))
    assert vec.at( 2) == 1
    assert vec.get_size() == 5
    vec.push( 14)
    vec.push( 15)
    vec.push( 14)
    vec.push( 15)
    vec.push( 14)
    vec.push( 14)
    vec.push( 15)
    vec.push( 14)
    vec.push( 15)
    vec.push( 14)
    vec.push( 15)
    assert vec.get_size() == 16
    assert vec.get_capacity() == 32
    vec.print_vec()
    vec.remove( 14)
    vec.print_vec()
    assert vec.get_size() == 10
    assert vec.find( 15) == 5
    assert vec.find( 20) == -1
    vec.delete(0)
    vec.delete(0)
    vec.delete(0)
    vec.delete(0)
    vec.delete(0)
    vec.print_vec()
    assert vec.get_size() == 5
    assert vec.get_capacity() == 16

if __name__ == "__main__":
    main()