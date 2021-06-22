from collections import deque

class Queue:
    def __init__(self):
        self.q = deque()

    def empty(self):
        return len(self.q) == 0

    def enqueue(self, value):
        self.q.append(value)

    def dequeue(self):
        return self.q.popleft()


def main():
    queue = Queue()
    assert queue.empty()
    try:
        assert queue.dequeue()
        assert 1==0
    except:
        pass

    queue.enqueue(1)
    assert not queue.empty()
    
    assert 1 == queue.dequeue()
    assert queue.empty()
    try:
        assert queue.dequeue()
        assert 1==0
    except:
        pass

    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    assert not queue.empty()
    
    assert 1 == queue.dequeue()
    assert not queue.empty()
    assert 2 == queue.dequeue()
    assert not queue.empty()
    assert 3 == queue.dequeue()
    assert queue.empty()

if __name__ == "__main__":
    main()