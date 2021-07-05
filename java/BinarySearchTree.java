public class BinarySearchTree {
    class Node {
        int data;
        Node left;
        Node right;

        public Node(int value) {
            this.data = value;
            left = right = null;
        }
    }

    private Node head;

    public BinarySearchTree() {
        head = null;
    }

    public static void asserting(boolean assertion) {
        if (!assertion) throw new RuntimeException();
    }

    public void insert(int item) {
        Node newNode = new Node(item);
        if (head == null) {
            head = newNode;
            return;
        }
        Node prev = null;
        Node ptr = head;
        while(ptr != null) {
            if (ptr.data > item) {
                prev = ptr;
                ptr = ptr.left;
            } else {
                prev = ptr;
                ptr = ptr.right;
            }
        }
        if (prev.data > item) {
            prev.left = newNode;
        } else {
            prev.right = newNode;
        }
    }

    public void delete_value(int key) {
        head = delete_value(key, head);
    }

    private Node delete_value(int key, Node node) {
        if (node == null) return node;
        if (key < node.data) {
            node.left = delete_value(key, node.left);
        }
        else if (key > node.data) {
            node.right = delete_value(key, node.right);
        }
        else {
            if (node.left == null && node.right == null) {
                return null;
            }
            else if (node.left == null) {
                return node.right;
            }
            else if (node.right == null) {
                return node.left;
            }
            else {
                Node succ = node.right;
                Node succ_parent = node;
                if (succ.left == null) {
                    succ_parent.data = succ.data;
                    succ_parent.right = succ.right;
                    succ = succ.left;
                } else {
                    while (succ.left != null) {
                        succ_parent = succ;
                        succ = succ.left;
                    }
                    node.data = succ.data;
                    succ_parent.left = succ.right;
                }
            }
        }
        return node;
    }

    public int get_node_count() {
        return get_node_count(head);
    }

    private int get_node_count(Node node) {
        if (node == null) return 0;
        return 1 + get_node_count(node.left) + get_node_count(node.right);
    }

    public void print_values() {
        System.out.println("BST: ");
        print_values(head);
        System.out.println("-----");
    }

    private void print_values(Node node) {
        if (node == null) return;
        print_values(node.left);
        System.out.println(node.data);
        print_values(node.right);
    }

    public void delete_tree() {
        head = null;
    }

    public boolean is_in_tree(int value) {
        return is_in_tree(value, head);
    }

    private boolean is_in_tree(int value, Node node) {
        if (node == null) return false;
        else if (node.data == value) return true;
        else {
            if (value < node.data) {
                return is_in_tree(value, node.left);
            } else {
                return is_in_tree(value, node.right);
            }
        }
    }

    public int get_height() {
        return get_height(head);
    }

    private int get_height(Node node) {
        if (node == null) return 0;
        return 1 + Math.max(get_height(node.left), get_height(node.right));
    }

    public int get_min() {
        return get_min(head).data;
    }

    private Node get_min(Node node) {
        if (node == null) return null;
        else if (node.left != null) {
            return get_min(node.left);
        }
        else {
            return node;
        }
    }

    public int get_max() {
        return get_max(head).data;
    }

    private Node get_max(Node node) {
        if (node == null) return null;
        else if (node.right != null) {
            return get_max(node.right);
        }
        else {
            return node;
        }
    }

    public boolean is_binary_search_tree() {
        return is_binary_search_tree(head, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean is_binary_search_tree(Node node, int minVal, int maxVal) {
        if (node == null) return true;
        return node.data > minVal &&
                node.data < maxVal &&
                is_binary_search_tree(node.left, minVal, node.data) &&
                is_binary_search_tree(node.right, node.data, maxVal);     
    }

    public int get_successor(int value) {
        Node succ = get_successor(value, head);
        return succ.data;
    }

    private Node get_successor(int value, Node node) {
        Node cur = get_node(value);
        if (cur.right != null) {
            return get_min(cur.right);
        } else {
            Node succ = null;
            Node ancestor = node;
            while (ancestor != null) {
                if (cur.data < ancestor.data) {
                    succ = ancestor;
                    ancestor = ancestor.left;
                } else {
                    ancestor = ancestor.right;
                }
            }
            return succ;
        }
    }

    private Node get_node(int value) {
        if (head == null) return null;
        Node ptr = head;
        while (ptr.data != value && ptr != null) {
            if (ptr.data > value) {
                ptr = ptr.left;
            } else {
                ptr = ptr.right;
            }
        }
        return ptr;
    }


    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(47);
        asserting(1 == bst.get_height());
        bst.insert(42);
        asserting(2 == bst.get_height());
        bst.insert(45);
        asserting(3 == bst.get_height());
        bst.insert(48);
        bst.insert(41);
        bst.insert(49);
        bst.print_values();
        asserting(6 == bst.get_node_count());

        asserting(true == bst.is_in_tree(41));
        asserting(true == bst.is_in_tree(42));
        asserting(false == bst.is_in_tree(43));
        asserting(false == bst.is_in_tree(44));
        asserting(true == bst.is_in_tree(45));
        asserting(false == bst.is_in_tree(46));
        asserting(true == bst.is_in_tree(47));
        asserting(true == bst.is_in_tree(48));
        asserting(true == bst.is_in_tree(49));

        asserting(3 == bst.get_height());
        asserting(49 == bst.get_max());
        asserting(41 == bst.get_min());
        asserting(true == bst.is_binary_search_tree());

        bst.print_values();
        bst.delete_value(47);
        bst.print_values();
        asserting(bst.is_in_tree(41));
        asserting(bst.is_in_tree(42));
        asserting(!bst.is_in_tree(43));
        asserting(false == bst.is_in_tree(44));
        asserting(true == bst.is_in_tree(45));
        asserting(false == bst.is_in_tree(46));
        asserting(false == bst.is_in_tree(47));
        asserting(true == bst.is_in_tree(48));
        asserting(true == bst.is_in_tree(49));
        asserting(5 == bst.get_node_count());
        bst.print_values();

        bst.delete_value(42);
        bst.print_values();
        asserting(bst.is_in_tree(41));
        asserting(!bst.is_in_tree(42));
        asserting(!bst.is_in_tree(43));
        asserting(false == bst.is_in_tree(44));
        asserting(true == bst.is_in_tree(45));
        asserting(false == bst.is_in_tree(46));
        asserting(false == bst.is_in_tree(47));
        asserting(true == bst.is_in_tree(48));
        asserting(true == bst.is_in_tree(49));
        asserting(4 == bst.get_node_count());
        bst.print_values();

        asserting(45 == bst.get_successor(41));
        asserting(48 == bst.get_successor(45));
        asserting(49 == bst.get_successor(48));

        bst.delete_value(48);
        asserting(3 == bst.get_node_count());
        bst.delete_value(49);
        bst.print_values();
        asserting(2 == bst.get_node_count());
        bst.delete_value(41);
        asserting(1 == bst.get_node_count());
        bst.delete_value(45);
        asserting(0 == bst.get_node_count());

        bst.delete_tree();
        asserting(0 == bst.get_node_count());
    }
}