#include "BST.cpp"

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