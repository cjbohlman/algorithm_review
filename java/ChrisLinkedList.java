import java.util.LinkedList;
import java.util.Collections;

public class ChrisLinkedList {

    private LinkedList<Integer> data;

    public ChrisLinkedList() {
        data = new LinkedList<Integer>();
    }

    public int getSize() {
        return data.size();
    }

    public boolean isEmpty() {
        return data.isEmpty();
    }

    public int valueAt(int index) {
        return (int) data.get(index);
    }

    public void pushFront(int value) {
        data.addFirst(value);
    }

    public void pushBack(int value) {
        data.addLast(value);
    }

    public Integer popFront() {
        return data.pollFirst();
    }

    public Integer popBack() {
        return data.pollLast();
    }

    public Integer front() {
        return data.peekFirst();
    }

    public Integer back() {
        return data.peekLast();
    }

    public void insert(int index, int value) {
        data.add(index, value);
    }

    public void erase(int index) {
        data.remove(index);
    }

    public void reverse() {
        Collections.reverse(data);
    }

    public void removeValue(int value) {
        data.removeFirstOccurrence(value);
    }

    public int value_n_from_end(int n) {
        return valueAt(getSize() - n - 1);
    }

    public void printList() {
        System.out.println("Printing out list of size "+getSize());
        for (int e : data) System.out.println(e);
    }

    public static void asserting(boolean assertion) {
        if (!assertion) throw new RuntimeException();
    }

    public static void main(String[] args) {
        ChrisLinkedList list = new ChrisLinkedList();
        ChrisLinkedList blank = new ChrisLinkedList();

        asserting(list.getSize() == 0);
        asserting(list.isEmpty());
        try {
            list.valueAt( 0);
            asserting(1==0);
        } catch(Exception e) {}
        try {
            list.valueAt(-1);
            asserting(1==0);
        } catch(Exception e) {}
        try {
            list.valueAt(1);
            asserting(1==0);
        } catch(Exception e) {}
        list.printList(); // 1

        list.pushFront(3);
        asserting(list.getSize() == 1);
        asserting(!list.isEmpty());
        asserting(list.valueAt(0) == 3);
        try {
            asserting(list.valueAt(1) == -1);
            asserting(1==0);
        } catch(Exception e) {}
        list.printList(); // 2

        list.pushFront(2);
        list.pushFront(1);
        asserting(list.getSize() == 3);
        asserting(!list.isEmpty());
        asserting(list.valueAt(0) == 1);
        asserting(list.valueAt(1) == 2);
        asserting(list.valueAt(2) == 3);
        try {
            asserting(list.valueAt(3) == -1);
            asserting(1==0);
        } catch(Exception e){}
        list.printList(); // 3

        asserting(list.popFront() == 1);
        asserting(list.getSize() == 2);
        asserting(!list.isEmpty());
        asserting(list.valueAt(0) == 2);
        asserting(list.valueAt(1) == 3);
        try {
            asserting(list.valueAt(2) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        asserting(list.popFront() == 2);
        asserting(list.popFront() == 3);
        asserting(list.getSize() == 0);
        asserting(list.isEmpty());
        try {
            asserting(list.valueAt(0) == -1);
        } catch(Exception e) {}
        asserting(list.popFront() == null);
        list.printList(); // 4

        list.pushBack(1);
        asserting(list.getSize() == 1);
        asserting(!list.isEmpty());
        list.printList(); // 5
        asserting(list.valueAt(0) == 1);
        try { 
            asserting(list.valueAt(1) == -1);
            asserting(1==0);
        } catch(Exception e) {}
        list.pushBack(2);
        list.pushBack(3);
        asserting(list.getSize() == 3);
        asserting(!list.isEmpty());
        asserting(list.valueAt(0) == 1);
        asserting(list.valueAt(1) == 2);
        asserting(list.valueAt(2) == 3);
        try { 
            asserting(list.valueAt(3) == -1);
            asserting(1==0);
        } catch(Exception e) {}
        list.printList();  // 6

        asserting(list.popBack() == 3);
        asserting(list.getSize() == 2);
        asserting(!list.isEmpty());
        asserting(list.valueAt(0) == 1);
        asserting(list.valueAt(1) == 2);
        try {
            asserting(list.valueAt(2) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        asserting(list.popBack() == 2);
        asserting(list.popBack() == 1);
        list.printList(); // 7
        asserting(list.getSize() == 0);
        asserting(list.isEmpty());
        try {
            asserting(list.valueAt(0) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        list.printList(); // 8
        asserting(list.popBack() == null);
        list.printList(); // 9

        asserting(list.front() == null);
        asserting(list.back() == null);
        list.pushBack(1);
        asserting(list.front() == 1);     
        asserting(list.back() == 1);  
        list.pushBack(2);
        list.pushFront(-1);
        asserting(list.front() == -1);
        asserting(list.back() == 2);  
        list.printList(); // 10

        list.insert(1, 0);
        list.printList();
        asserting(list.getSize() == 4);
        asserting(list.valueAt(0) == -1);
        asserting(list.valueAt(1) == 0);
        asserting(list.valueAt(2) == 1);
        list.insert(0, -2);
        asserting(list.getSize() == 5);
        asserting(list.valueAt(0) == -2);
        asserting(list.valueAt(1) == -1);
        asserting(list.valueAt(2) == 0);
        list.insert(0, -3);
        asserting(list.getSize() == 6);
        asserting(list.valueAt(0) == -3);
        asserting(list.valueAt(1) == -2);
        asserting(list.valueAt(2) == -1);
        list.insert(6, 3);
        asserting(list.getSize() == 7);
        asserting(list.valueAt(4) == 1);
        asserting(list.valueAt(5) == 2);
        asserting(list.valueAt(6) == 3);
        try {
            list.insert(10, 10);
            asserting(1 == 0);
        } catch(Exception e) {}
        asserting(list.getSize() == 7);
        try {
            list.insert(-1, 10);
            asserting(1 == 0);
        } catch(Exception e) {}
        asserting(list.getSize() == 7);
        list.printList();

        list.erase(0);  
        list.printList();  
        asserting(list.getSize() == 6);
        asserting(list.valueAt(0) == -2);
        list.erase(1);
        list.printList();
        asserting(list.getSize() == 5);
        asserting(list.valueAt(0) == -2);
        asserting(list.valueAt(1) == 0);
        list.erase(3);
        asserting(list.getSize() == 4);
        asserting(list.valueAt(0) == -2);
        asserting(list.valueAt(1) == 0);
        asserting(list.valueAt(2) == 1);
        asserting(list.valueAt(3) == 3);
        try {
            asserting(list.valueAt(4) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        list.erase(3);
        asserting(list.getSize() == 3);
        asserting(list.valueAt(0) == -2);
        asserting(list.valueAt(1) == 0);
        asserting(list.valueAt(2) == 1);
        try {
            asserting(list.valueAt(3) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        list.printList();

        try {
            asserting(list.value_n_from_end(-1) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        asserting(list.value_n_from_end(0) == 1);
        asserting(list.value_n_from_end(1) == 0);
        asserting(list.value_n_from_end(2) == -2);
        try {
            asserting(list.value_n_from_end(3) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        list.printList();

        list.reverse();
        try {
            asserting(list.value_n_from_end(-1) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        list.printList();
        asserting(list.value_n_from_end(2) == 1);
        asserting(list.value_n_from_end(1) == 0);
        asserting(list.value_n_from_end(0) == -2);
        try {
            asserting(list.value_n_from_end(3) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        try {
            asserting(list.valueAt(-1) == -1);
            asserting(1== 0);
        } catch(Exception e) {}
        asserting(list.valueAt(0) == 1);
        asserting(list.valueAt(1) == 0);
        asserting(list.valueAt(2) == -2);
        try {
            asserting(list.valueAt(3) == -1);
            asserting(1 == 0);
        } catch(Exception e) {}
        list.printList();

        list.pushBack(-3);
        asserting(list.getSize() == 4);
        list.removeValue(-8);
        asserting(list.getSize() == 4);
        list.removeValue(-2);
        asserting(list.getSize() == 3);
        asserting(list.valueAt(0) == 1);
        asserting(list.valueAt(1) == 0);
        asserting(list.valueAt(2) == -3);
        list.removeValue(-3);
        asserting(list.getSize() == 2);
        asserting(list.valueAt(0) == 1);
        asserting(list.valueAt(1) == 0);
        list.removeValue(1);
        asserting(list.getSize() == 1);
        asserting(list.valueAt(0) == 0);
        list.removeValue(0);
        asserting(list.getSize() == 0);

        blank.removeValue(2);
        blank.reverse();
        try {
            asserting(blank.value_n_from_end(0) == 0);
            asserting(1 == 0);
        } catch(Exception e) {}
        try {
            blank.erase(0);
            asserting(1 == 0);
        } catch(Exception e) {}
        try {
            blank.erase(1);
            asserting(1 == 0);
        } catch(Exception e) {}
    }
}