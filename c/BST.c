#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

struct Tree {
    Node *root;
};

int max(int one, int two) {
    if (one >= two) return one;
    else return two;
}

void insert(Node **root, int value) {
    Node **walk = root;
    while (*walk != NULL) {
        int cur = (*walk)->data;
        if (cur == value) return;
        else if (cur < value) {
            walk = &(*walk)->right;
        } else {
            walk = &(*walk)->left;
        }
    }
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;
    *walk = newNode;
}

Node * find(Node *root, int key) {
    if (root == NULL) return NULL;
    while (root->data != key) {
        if (root->data > key) root = root->left;
        else root = root->right;
    }
    if (root->data == key) return root;
    else return NULL;
}

void print_values(Node *node) {
    if (node == NULL) return;
    print_values(node->left);
    printf("%d\n", node->data);
    print_values(node->right);
}

int get_node_count(Node *node) {
    if (node == NULL) return 0;
    return 1 + get_node_count(node->left) + get_node_count(node->right);
}

void delete_tree(Node *node) {
    if (node == NULL) return;
    delete_tree(node->left);
    delete_tree(node->right);
    free(node);
}

int is_in_tree(Node *node, int value) {
    if (node == NULL) return 0;
    else if (node->data == value) return 1;
    else return is_in_tree(node->left, value) || is_in_tree(node->right, value);
}

int get_height(Node *node) {
    if (node == NULL) return 0;
    else return 1 + max(get_height(node->left), get_height(node->right));
}

int get_min(Node *node) {
    Node *ptr = node;
    if (ptr == NULL) return 0;
    while (ptr->left != NULL) ptr = ptr->left;
    return ptr->data;
}

Node * get_min_node(Node *node) {
    Node *ptr = node;
    if (ptr == NULL) return 0;
    while (ptr->left != NULL) ptr = ptr->left;
    return ptr;
}

int get_max(Node *node) {
    Node *ptr = node;
    if (ptr == NULL) return 0;
    while (ptr->right != NULL) ptr = ptr->right;
    return ptr->data;
}

int is_BST_helper(Node *root, int minVal, int maxVal) {
    if (root == 0) return 1;

    if (root->data > minVal 
        && root->data < maxVal
        && is_BST_helper(root->left, minVal, root->data)
        && is_BST_helper(root->right, root->data, maxVal)) return 1;
    else return 0;    
}

int is_binary_search_tree(Node *root) {
    return is_BST_helper(root, INT_MIN, INT_MAX);
}

Node * delete_value(Node *root, int key) {
    if (root == NULL) return root;
    else if (key < root->data) root->left = delete_value(root->left, key);
    else if (key > root->data) root->right = delete_value(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            // case 1: no child
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            // one child
            Node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            // one child
            Node *temp = root;
            root = root->left;
            free(temp);
        } else {
            // 2 children
            Node *temp = get_min_node(root->right);
            root->data = temp->data;
            root->right = delete_value(root->right, temp->data);
        }
    }
    return root;
}

Node * inorder_succession(Node * root, int key) {
    Node *cur = find(root, key);
    if (cur == NULL) return NULL;
    if (cur->right != NULL) return get_min_node(cur->right);
    else {
        Node *succ = NULL;
        Node *ancestor = root;

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