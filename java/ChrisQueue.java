import java.util.Queue;
import java.util.LinkedList;

public class ChrisQueue {
    private Queue<Integer> queue;

    public ChrisQueue() {
        queue = new LinkedList<>();
    }

    public boolean empty() {
        return queue.isEmpty();
    }

    public void enqueue(int value) {
        queue.add(value);
    }

    public int dequeue() {
        return queue.poll();
    }

    public static void asserting(boolean assertingion) {
        if (!assertingion) throw new RuntimeException();
    }

    public static void main(String[] args) {
        ChrisQueue queue = new ChrisQueue();
        asserting(queue.empty());
        try {
            asserting(queue.dequeue() == -1);
            asserting(1==0);
        } catch(Exception e) {}

        queue.enqueue(1);
        asserting(!queue.empty());
        
        asserting(1 == queue.dequeue());
            asserting(queue.empty());
        try {
            asserting(queue.dequeue() == -1);
            asserting(1==0);
        } catch(Exception e) {}

        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        asserting(!queue.empty());
        
        asserting(1 == queue.dequeue());
        asserting(!queue.empty());
        asserting(2 == queue.dequeue());
        asserting(!queue.empty());
        asserting(3 == queue.dequeue());
        asserting(queue.empty());
    }
}