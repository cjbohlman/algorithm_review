import java.util.ArrayList;
import java.util.List;

public class DynamicArray {

    private List<Integer> data;

    public DynamicArray() {
        data = new ArrayList<Integer>(16);
    }

    public int size() {
        return this.data.size();
    }

    public boolean isEmpty() {
        return this.size() == 0;
    }

    public int at(int index) {
        return data.get(index);
    }

    public void insert(int index, int element) {
        this.data.add(index, element);
    }

    public void push(int element) {
        this.data.add(element);
    }

    public void pop() {
        this.data.remove(this.data.size() - 1);
    }

    public void delete(int index) {
        this.data.remove(index);
    }

    public void prepend(int element) {
        this.insert(0, element);
    }

    public int find(int element) {
        return this.data.indexOf(element);
    }

    public void remove(int element) {
        int itemIndex = this.data.indexOf(element);
        while (itemIndex != -1) {
            this.print_vec();
            this.delete(itemIndex);
            itemIndex = this.data.indexOf(element);
        }

    }

    public void print_vec() {
        System.out.println("Printing vec:");
        for (int i = 0; i < this.size(); i++) {
            System.out.println(this.at(i));
        }
    }

    public static void asserting(boolean assertion) {
        if (!assertion) throw new RuntimeException();
    }

    public static void main(String[] args) {
        DynamicArray vec = new DynamicArray();
        asserting(vec.isEmpty());
        for (int i=0; i <= 5; i++) {
            vec.push( i);
        }

        asserting(vec.size() == 6);
        asserting(vec.at( 0) == 0);
        asserting(vec.at( 1) == 1);
        asserting(vec.at( 2) == 2);
        asserting(vec.at( 3) == 3);
        asserting(vec.at( 4) == 4);
        asserting(vec.at( 5) == 5);
        vec.pop();
        vec.pop();
        asserting(vec.size() == 4);
        vec.print_vec();
        vec.prepend( -2);
        vec.print_vec();
        vec.insert( 1, -1);
        vec.print_vec();
        vec.delete( 2);
        vec.print_vec();
        asserting(vec.at( 0) == -2);
        asserting(vec.at( 1) == -1);
        asserting(vec.at( 2) == 1);
        asserting(vec.size() == 5);
        vec.push( 14);
        vec.push( 15);
        vec.push( 14);
        vec.push( 15);
        vec.push( 14);
        vec.push( 14);
        vec.push( 15);
        vec.push( 14);
        vec.push( 15);
        vec.push( 14);
        vec.push( 15);
        asserting(vec.size() == 16);
        vec.print_vec();
        vec.remove(14);
        vec.print_vec();
        asserting(vec.size() == 10);
        asserting(vec.find( 15) == 5);
        asserting(vec.find( 20) == -1);
        vec.delete(0);
        vec.delete(0);
        vec.delete(0);
        vec.delete(0);
        vec.delete(0);
        vec.print_vec();
        asserting(vec.size() == 5);
    }

    
}