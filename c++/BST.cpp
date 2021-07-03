#include<memory>
#include<iostream>
#include<cassert>
#include<cmath>
#include<limits>

class BST {
private:
    struct Node {
        int data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };

    std::shared_ptr<Node> head;
    void insert(int, std::shared_ptr<Node> &);
    void print_values(const std::shared_ptr<Node>);
    int get_node_count(const std::shared_ptr<Node>);
    int get_height(const std::shared_ptr<Node>);
    bool is_in_tree(int key, const std::shared_ptr<Node>);
    int get_max(const std::shared_ptr<Node>);
    int get_min(const std::shared_ptr<Node>);
    bool is_binary_search_tree(const std::shared_ptr<Node>, int, int);
    std::shared_ptr<Node> get_node(int key, std::shared_ptr<Node> node) {
        if (node == nullptr) return nullptr;
        while (node->data != key) {
            if (node->data > key) node = node->left;
            else node = node->right;
        }
        if (node->data == key) return node;
        else return nullptr;
    }
    void delete_value(const int &, std::shared_ptr<Node> &);
    std::shared_ptr<Node> inorder_succession(int value, std::shared_ptr<Node>) {
        auto cur = get_node(value, head);
        if (cur->right != nullptr) {
            cur = cur->right;
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            return cur;
        } else {
            std::shared_ptr<Node> succ= nullptr;
            auto ancestor = head;
            while (ancestor != cur) {
                if (cur->data < ancestor->data) {
                    succ = ancestor;
                    ancestor = ancestor->left;
                } else {
                    ancestor = ancestor->right;
                }
            }
            return succ;
        }
    }

public:

    BST();
    void insert(int);
    void print_values();
    int get_node_count();
    int get_height();
    bool is_in_tree(int key);
    int get_max();
    int get_min();
    void delete_tree();
    bool is_binary_search_tree();
    void delete_value(int);
    int inorder_succession(int);
    

};

BST::BST() {
    head = nullptr;
}

void BST::insert(int key) {
    insert(key, head);
}

void BST::insert(int key, std::shared_ptr<Node> & node) {
    if (node == nullptr) node = std::make_shared<Node>(Node{key, nullptr, nullptr});
    else if (node->data == key) return;
    else if (node->data > key) insert(key, node->left);
    else insert(key, node->right);
}

void BST::print_values() {
    std::cout << "Printing BST: " << std::endl;
    print_values(head);
    std::cout << "--------------" << std::endl;
}

void BST::print_values(const std::shared_ptr<Node> node) {
    if (node == nullptr) return;
    print_values(node->left);
    std::cout << node->data << std::endl;
    print_values(node->right);
}

int BST::get_node_count() {
    return get_node_count(head);
}

int BST::get_node_count(const std::shared_ptr<Node> node) {
    if (node == nullptr) return 0;
    else return 1 + get_node_count(node->left) + get_node_count(node->right);
}

int BST::get_height() {
    return get_height(head);
}

int BST::get_height(const std::shared_ptr<Node> node) {
    if (node == nullptr) return 0;
    else return 1 + fmax(get_height(node->left), get_height(node->right));
}

bool BST::is_in_tree(int key) {
    return is_in_tree(key, head);
}

bool BST::is_in_tree(int key, const std::shared_ptr<Node> node) {
    if (node == nullptr) return false;
    else if (node->data == key) return true;
    else return is_in_tree(key, node->left) || is_in_tree(key, node->right);
}

int BST::get_max() {
    if (head == nullptr) return -1;
    return get_max(head);
}

int BST::get_max(const std::shared_ptr<Node> node) {
    if (node->right == nullptr) return node->data;
    else return get_max(node->right);
}
int BST::get_min() {
    if (head == nullptr) return -1;
    return get_min(head);
}

int BST::get_min(const std::shared_ptr<Node> node) {
    if (node->left == nullptr) return node->data;
    else return get_min(node->left);
}

void BST::delete_tree() {
    head = nullptr;
}

bool BST::is_binary_search_tree() {
    return is_binary_search_tree(head, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

bool BST::is_binary_search_tree(const std::shared_ptr<Node> node, int minValue, int maxValue) {
    if (node == nullptr) return true;
    else if (node->data > minValue &&
             node->data < maxValue &&
             is_binary_search_tree(node->left, minValue, node->data) &&
             is_binary_search_tree(node->right, node->data, maxValue)) return true;
    else return false;
}

void BST::delete_value(const int &value, std::shared_ptr<Node> & node) {
    if (node == nullptr) return;
    else if (value < node->data) delete_value(value, node->left);
    else if (value > node->data) delete_value(value, node->right);
    else {
        if (node->left == nullptr && node->right == nullptr) {
            node = nullptr;
        } else if (node-> left == nullptr) {
            node = node->right;
        } else if (node-> right == nullptr) {
            node = node->left;
        } else {
            std::shared_ptr<Node> succ = node->right;
            std::shared_ptr<Node> succ_parent = node;
            if (succ->left == nullptr) {
                node->data = succ->data;
                node->right = succ->right;
            } else {
                while (succ->left != nullptr)  {
                    succ_parent = succ;
                    succ = succ->left;
                }
                // replace k wih k's succ
                node->data = succ->data;
                // make the succ's parent point to succ's right subtree
                succ_parent->left = succ->right;
            }
        }
    }
}

void BST::delete_value(int value) {
    delete_value(value, head);
}

int BST::inorder_succession(int value) {
    return inorder_succession(value, head)->data;
}

int main() {
    BST bst{};
    bst.insert(47);
    assert(1 == bst.get_height());
    bst.insert(42);
    assert(2 == bst.get_height());
    bst.insert(45);
    assert(3 == bst.get_height());
    bst.insert(48);
    bst.insert(41);
    bst.insert(49);
    bst.print_values();
    assert(6 == bst.get_node_count());

    assert(true == bst.is_in_tree(41));
    assert(true == bst.is_in_tree(42));
    assert(false == bst.is_in_tree(43));
    assert(false == bst.is_in_tree(44));
    assert(true == bst.is_in_tree(45));
    assert(false == bst.is_in_tree(46));
    assert(true == bst.is_in_tree(47));
    assert(true == bst.is_in_tree(48));
    assert(true == bst.is_in_tree(49));

    assert(3 == bst.get_height());
    assert(49 == bst.get_max());
    assert(41 == bst.get_min());
    assert(true == bst.is_binary_search_tree());

    bst.delete_value(47);
    assert(1 == bst.is_in_tree(41));
    assert(1 == bst.is_in_tree(42));
    assert(0 == bst.is_in_tree(43));
    assert(0 == bst.is_in_tree(44));
    assert(1 == bst.is_in_tree(45));
    assert(0 == bst.is_in_tree(46));
    assert(0 == bst.is_in_tree(47));
    assert(1 == bst.is_in_tree(48));
    assert(1 == bst.is_in_tree(49));
    assert(5 == bst.get_node_count());
    bst.print_values();

    bst.delete_value(42);
    bst.print_values();
    assert(1 == bst.is_in_tree(41));
    assert(0 == bst.is_in_tree(42));
    assert(0 == bst.is_in_tree(43));
    assert(0 == bst.is_in_tree(44));
    assert(1 == bst.is_in_tree(45));
    assert(0 == bst.is_in_tree(46));
    assert(0 == bst.is_in_tree(47));
    assert(1 == bst.is_in_tree(48));
    assert(1 == bst.is_in_tree(49));
    assert(4 == bst.get_node_count());
    bst.print_values();

    assert(45 == bst.inorder_succession(41));
    assert(48 == bst.inorder_succession(45));
    assert(49 == bst.inorder_succession(48));

    bst.delete_value(48);
    assert(3 == bst.get_node_count());
    bst.delete_value(49);
    bst.print_values();
    assert(2 == bst.get_node_count());
    bst.delete_value(41);
    assert(1 == bst.get_node_count());
    bst.delete_value(45);
    assert(0 == bst.get_node_count());

    bst.delete_tree();
    assert(0 == bst.get_node_count());
}