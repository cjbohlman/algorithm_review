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