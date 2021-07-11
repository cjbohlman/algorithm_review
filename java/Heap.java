public class Heap {
    private int[] arr;
    private int size;
    
    public Heap() {
        this.arr = new int[101];
        this.size = 0;
    }

    public Heap(int[] arr) {
        this.arr = new int[101];
        this.size = 0;
        int index = 1;
        for (int i : arr) {
            this.arr[index] = i;
            index++;
        }
        this.size = index - 1;
    }

    public boolean is_empty() {
        return this.size == 0;
    }

    public int get_size() {
        return this.size;
    }

    public void insert(int value) {
        if (this.size == 100) return;
        this.size++;
        this.arr[this.size] = value;
        sift_up(this.size);
    }

    public void sift_up(int index) {
        while (this.arr[parent(index)] < this.arr[index]) {
            int temp = this.arr[parent(index)];
            this.arr[parent(index)] = this.arr[index];
            this.arr[index] = temp;
            index = parent(index);
        }
    }

    private int parent(int index) {
        if (index == 1) return 1;
        else return (int) Math.floor(index/2);
    }

    private int left(int index) {
        return index * 2;
    }

    private int right(int index) {
        return index * 2 + 1;
    }

    public int extract_max() {
        if (this.size == 0) {
            throw new RuntimeException();
        }
        int retVal = this.arr[1];
        this.size--;
        if (size > 0) {
            this.arr[1] = this.arr[size+1];
            max_heapify(1);
        }
        return retVal;
    }

    public void max_heapify(int index) {
        int largest = index;
        int left = left(index);
        int right = right(index);
        if (left <= this.size && this.arr[left] > this.arr[largest]) {
            largest = left;
        }
        if (right <= this.size && this.arr[right] > this.arr[largest]) {
            largest = right;
        }
        if (largest != index) {
            int temp = this.arr[index];
            this.arr[index] = this.arr[largest];
            this.arr[largest] = temp;
            max_heapify(largest);
        }
    }

    public int[] get_arr() {
        return this.arr;
    }

    public void print_heap() {
        System.out.println("Printing heap:");
        for (int i = 1; i <= this.size; i++) {
            System.out.println(this.arr[i]);
        }
        System.out.println("----------------------");
        
    }

    public void remove(int index) {
        this.arr[index] = this.arr[this.size];
        this.size--;
        max_heapify(index);
    }

    public void build_max_heap() {
        for(int i = (int) Math.floor(this.size/2); i >= 1; i--) {
            max_heapify(i);
        }
    }

    public void heap_sort() {
        build_max_heap();
        int end = this.size;
        while (end > 1) {
            int temp = this.arr[1];
            this.arr[1] = this.arr[end];
            this.arr[end] = temp;
            this.size--;
            max_heapify(1);
            end--;
        }
    }

    public static void asserting(boolean assertion) {
        if (!assertion) throw new RuntimeException();
    }

    public static void main(String[] args) {
        Heap heap = new Heap();
        asserting(heap.is_empty());
        asserting(0 == heap.get_size());

        // test insertion and subsequent max heap
        heap.insert(1);
        heap.insert(2);
        heap.insert(3);
        heap.insert(4);
        heap.insert(5);
        heap.insert(6);
        heap.insert(7);

        asserting(!heap.is_empty());
        asserting(7 == heap.get_size());
        heap.print_heap();

        asserting(7 == heap.extract_max());
        asserting(6 == heap.get_size());
        asserting(6 == heap.extract_max());
        asserting(5 == heap.get_size());
        asserting(5 == heap.extract_max());
        asserting(4 == heap.get_size());
        asserting(4 == heap.extract_max());
        asserting(3 == heap.get_size());
        asserting(3 == heap.extract_max());
        asserting(2 == heap.get_size());
        asserting(2 == heap.extract_max());
        asserting(1 == heap.get_size());
        asserting(1 == heap.extract_max());
        asserting(0 == heap.get_size());
        asserting(heap.is_empty());

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
        int[] newArr = new int[100];
        int index = 0;
        for (int i = 100; i >= 1; i--) {
            newArr[index] = i;
            index++;
        }
        Heap heap2 = new Heap(newArr);

        asserting(!heap2.is_empty());
        asserting(100 == heap2.get_size());
        heap2.build_max_heap();
        heap2.print_heap();
        asserting(100 == heap2.extract_max());
        asserting(99 == heap2.extract_max());
        asserting(98 == heap2.extract_max());
        asserting(97 == heap2.extract_max());
        asserting(96 == heap2.extract_max());
        asserting(95 == heap2.extract_max());
        asserting(94 == heap2.extract_max());
        asserting(93 == heap2.extract_max());
        asserting(92 == heap2.extract_max());
        asserting(91 == heap2.extract_max());
        asserting(90 == heap2.extract_max());
        asserting(89 == heap2.extract_max());
        asserting(88 == heap2.extract_max());
        asserting(87 == heap2.extract_max());
        asserting(86 == heap2.extract_max());
        asserting(85 == heap2.extract_max());
        asserting(84 == heap2.extract_max());
        asserting(83 == heap2.extract_max());
        asserting(82 == heap2.extract_max());
        asserting(81 == heap2.extract_max());
        asserting(80 == heap2.extract_max());
        asserting(79 == heap2.extract_max());
        asserting(78 == heap2.extract_max());
        asserting(77 == heap2.extract_max());
        asserting(76 == heap2.extract_max());
        asserting(75 == heap2.extract_max());
        asserting(74 == heap2.extract_max());
        asserting(73 == heap2.extract_max());
        asserting(72 == heap2.extract_max());
        asserting(71 == heap2.extract_max());
        asserting(70 == heap2.extract_max());
        asserting(69 == heap2.extract_max());
        asserting(68 == heap2.extract_max());
        asserting(67 == heap2.extract_max());
        asserting(66 == heap2.extract_max());
        asserting(65 == heap2.extract_max());
        asserting(64 == heap2.extract_max());
        asserting(63 == heap2.extract_max());
        asserting(62 == heap2.extract_max());
        asserting(61 == heap2.extract_max());
        asserting(60 == heap2.extract_max());
        asserting(59 == heap2.extract_max());
        asserting(58 == heap2.extract_max());
        asserting(57 == heap2.extract_max());
        asserting(56 == heap2.extract_max());
        asserting(55 == heap2.extract_max());
        asserting(54 == heap2.extract_max());
        asserting(53 == heap2.extract_max());
        asserting(52 == heap2.extract_max());
        asserting(51 == heap2.extract_max());
        asserting(50 == heap2.extract_max());
        asserting(49 == heap2.extract_max());
        asserting(48 == heap2.extract_max());
        asserting(47 == heap2.extract_max());
        asserting(46 == heap2.extract_max());
        asserting(45 == heap2.extract_max());
        asserting(44 == heap2.extract_max());
        asserting(43 == heap2.extract_max());
        asserting(42 == heap2.extract_max());
        asserting(41 == heap2.extract_max());
        asserting(40 == heap2.extract_max());
        asserting(39 == heap2.extract_max());
        asserting(38 == heap2.extract_max());
        asserting(37 == heap2.extract_max());
        asserting(36 == heap2.extract_max());
        asserting(35 == heap2.extract_max());
        asserting(34 == heap2.extract_max());
        asserting(33 == heap2.extract_max());
        asserting(32 == heap2.extract_max());
        asserting(31 == heap2.extract_max());
        asserting(30 == heap2.extract_max());
        asserting(29 == heap2.extract_max());
        asserting(28 == heap2.extract_max());
        asserting(27 == heap2.extract_max());
        asserting(26 == heap2.extract_max());
        asserting(25 == heap2.extract_max());
        asserting(24 == heap2.extract_max());
        asserting(23 == heap2.extract_max());
        asserting(22 == heap2.extract_max());
        asserting(21 == heap2.extract_max());
        asserting(20 == heap2.extract_max());
        asserting(19 == heap2.extract_max());
        asserting(18 == heap2.extract_max());
        asserting(17 == heap2.extract_max());
        asserting(16 == heap2.extract_max());
        heap2.print_heap();
        asserting(15 == heap2.extract_max());
        asserting(14 == heap2.extract_max());
        asserting(13 == heap2.extract_max());
        asserting(12 == heap2.extract_max());
        asserting(11 == heap2.extract_max());
        asserting(10 == heap2.extract_max());
        asserting(9 == heap2.extract_max());
        asserting(8 == heap2.extract_max());
        asserting(7 == heap2.extract_max());
        asserting(6 == heap2.extract_max());
        asserting(5 == heap2.extract_max());
        asserting(4 == heap2.extract_max());
        asserting(3 == heap2.extract_max());
        asserting(2 == heap2.extract_max());
        asserting(1 == heap2.extract_max());
            
        // test heapsort on already created array
        int[] newArr2 = new int[100];
        index = 0;
        for (int i = 100; i >= 1; i--) {
            newArr2[index] = i;
            index++;
        }
        Heap heap3 = new Heap(newArr2);
        asserting(!heap3.is_empty());

        heap3.heap_sort();
        int[] vec = heap3.get_arr();
        System.out.println("Printing sorted array:");
        for (int i = 1; i <= 100; i++) {
            System.out.println(vec[i]);
        }
        System.out.println("----------------------");
        for (int i = 1; i <= 100; i++) {
            asserting(i == vec[i]);
        }
    }
}