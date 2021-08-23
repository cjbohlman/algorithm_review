#include "BST.h"

int main() {
    Node *root = NULL;
    printf("Printing BST in order: \n");
    print_values(root);
    printf("----------------------\n");
    assert(0 == get_node_count(root));

    insert(&root, 47);
    assert(1 == get_height(root));
    insert(&root, 42);
    assert(2 == get_height(root));
    insert(&root, 45);
    assert(3 == get_height(root));
    insert(&root, 48);
    insert(&root, 41);
    insert(&root, 49);
    printf("Printing BST in order: \n");
    print_values(root);
    printf("----------------------\n");
    assert(6 == get_node_count(root));

    assert(1 == is_in_tree(root, 41));
    assert(1 == is_in_tree(root, 42));
    assert(0 == is_in_tree(root, 43));
    assert(0 == is_in_tree(root, 44));
    assert(1 == is_in_tree(root, 45));
    assert(0 == is_in_tree(root, 46));
    assert(1 == is_in_tree(root, 47));
    assert(1 == is_in_tree(root, 48));
    assert(1 == is_in_tree(root, 49));

    assert(3 == get_height(root));
    assert(49 == get_max(root));
    assert(41 == get_min(root));

    assert(42 == inorder_succession(root, 41)->data);
    assert(45 == inorder_succession(root, 42)->data);
    assert(47 == inorder_succession(root, 45)->data);
    assert(48 == inorder_succession(root, 47)->data);
    assert(49 == inorder_succession(root, 48)->data);

    assert(1 == is_binary_search_tree(root));

    delete_value(root, 47);
    assert(1 == is_in_tree(root, 41));
    assert(1 == is_in_tree(root, 42));
    assert(0 == is_in_tree(root, 43));
    assert(0 == is_in_tree(root, 44));
    assert(1 == is_in_tree(root, 45));
    assert(0 == is_in_tree(root, 46));
    assert(0 == is_in_tree(root, 47));
    assert(1 == is_in_tree(root, 48));
    assert(1 == is_in_tree(root, 49));
    assert(5 == get_node_count(root));
    
    printf("Printing BST in order: \n");
    print_values(root);
    printf("----------------------\n");

    delete_value(root, 42);
    assert(1 == is_in_tree(root, 41));
    assert(0 == is_in_tree(root, 42));
    assert(0 == is_in_tree(root, 43));
    assert(0 == is_in_tree(root, 44));
    assert(1 == is_in_tree(root, 45));
    assert(0 == is_in_tree(root, 46));
    assert(0 == is_in_tree(root, 47));
    assert(1 == is_in_tree(root, 48));
    assert(1 == is_in_tree(root, 49));
    assert(4 == get_node_count(root));
    printf("Printing BST in order: \n");
    print_values(root);
    printf("----------------------\n");

    assert(45 == inorder_succession(root, 41)->data);
    assert(48 == inorder_succession(root, 45)->data);
    assert(49 == inorder_succession(root, 48)->data);

    delete_tree(root);
}