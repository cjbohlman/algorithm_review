class BST(object):

    def __init__(self):
        self.root = None

    def insert(self, d):
        if self.root:
            return self.root.insert(d)
        else:
            self.root = Node(d)
            return True

    def get_node_count(self):
        if self.root:
            return self.root.get_node_count()
        else:
            return 0

    def print_values(self):
        print("binary tree:")
        if self.root:
            self.root.print_values()
        print("------------")

    def delete_tree(self):
        self.root = None

    def is_in_tree(self, d):
        if self.root:
            return self.root.is_in_tree(d)
        else:
            return False

    def get_height(self):
        if self.root:
            return self.root.get_height()
        else:
            return 0

    def get_min(self):
        if self.root:
            return self.root.get_min().data
        else:
            return -1

    def get_max(self):
        if self.root:
            return self.root.get_max().data
        else:
            return -1

    def is_binary_search_tree(self):
        return is_binary_search_tree_util(self.root, -4294967296, 4294967296)

    def delete_value(self, d):
        self.root = delete_value_util(self.root, d)

    def get_successor(self, value):
        return self.root.get_successor(value).data

    
def is_binary_search_tree_util(node, minVal, maxVal):
        if node is None:
            return True

        if node.data > minVal and node.data < maxVal and is_binary_search_tree_util(node.left, minVal, node.data) and is_binary_search_tree_util(node.right, node.data, maxVal):
            return True
        else:
            return False

def delete_value_util(node, value):
    if node is None:
        pass
    elif value < node.data:
        node.left = delete_value_util(node.left, value)
    elif value > node.data:
        node.right = delete_value_util(node.right, value)
    else:
        if node.left is None and node.right is None:
            return None
        elif node.left is None:
            return node.right
        elif node.right is None:
            return node.left
        else:
            succ = node.right
            succ_parent = node
            if succ.left is None:
                node.data = succ.data
                node.right = succ.right
            else:
                while succ.left:
                    succ_parent = succ
                    succ = succ.left
                node.data = succ.data
                succ_parent.left = succ.right
    return node

class Node(object):

    def __init__(self, d):
        self.data = d
        self.left = None
        self.right = None

    def insert(self, d):
        if self.data == d:
            return False
        elif self.data > d:
            if self.left:
                return self.left.insert(d)
            else:
                self.left = Node(d)
                return True
        else:
            if self.right:
                return self.right.insert(d)
            else:
                self.right = Node(d)
                return True

    def get_node_count(self):
        count = 1
        if self.left:
            count += self.left.get_node_count()
        if self.right:
            count += self.right.get_node_count()
        return count

    def print_values(self):
        if self.left:
            self.left.print_values()
        print(self.data)
        if self.right:
            self.right.print_values()

    def is_in_tree(self, d):
        if self.data == d:
            return True
        left = False
        if self.left:
            left = self.left.is_in_tree(d)
        right = False
        if self.right:
            right = self.right.is_in_tree(d)
        return left or right

    def get_height(self):
        left = 0
        right = 0
        if self.left:
            left = self.left.get_height()
        if self.right:
            right = self.right.get_height()
        return 1 + max(left, right)

    def get_min(self):
        if self.left:
            return self.left.get_min()
        else:
            return self

    def get_max(self):
        if self.right:
            return self.right.get_max()
        else:
            return self

    def get_successor(self, value):
        cur = self.get_node(value)
        if cur.right:
            return cur.right.get_min()
        else:
            succ = None
            ancestor = self
            while ancestor != cur:
                if cur.data < ancestor.data:
                    succ = ancestor
                    ancestor = ancestor.left
                else:
                    ancestor = ancestor.right
            return succ
                

    def get_node(self, d):
        if self.data == d:
            return self
        elif d < self.data:
            if self.left:
                if self.left.get_node(d):
                    return self.left.get_node(d)
        else:
            if self.right:
                if self.right.get_node(d):
                    return self.right.get_node(d)
        return None
    

def main():
    bst = BST()

    assert 0 == bst.get_node_count()
    assert not bst.is_in_tree(4)
    assert 0 == bst.get_height()
    assert bst.is_binary_search_tree()

    assert bst.insert(2)
    assert not bst.insert(2)
    assert 1 == bst.get_height()
    assert 2 == bst.get_max()
    assert 2 == bst.get_min()
    assert bst.insert(1)
    assert bst.insert(3)

    assert 3 == bst.get_node_count()

    bst.print_values()

    assert not bst.is_in_tree(0)
    assert bst.is_in_tree(1)
    assert bst.is_in_tree(2)
    assert bst.is_in_tree(3)
    assert not bst.is_in_tree(4)
    assert 2 == bst.get_height()
    assert 3 == bst.get_max()
    assert 1 == bst.get_min()
    assert bst.is_binary_search_tree()

    bst.delete_tree()

    bst.insert(45)
    bst.insert(43)
    bst.insert(47)
    bst.insert(42)
    bst.insert(44)
    bst.insert(46)
    bst.insert(48)
    assert bst.is_binary_search_tree()
    assert 43 == bst.get_successor(42)
    assert 44 == bst.get_successor(43)
    assert 45 == bst.get_successor(44)
    assert 46 == bst.get_successor(45)
    assert 47 == bst.get_successor(46)
    assert 48 == bst.get_successor(47)

    print("before deletions")
    bst.print_values()
    bst.delete_value(45)
    bst.print_values()
    bst.delete_value(47)
    bst.print_values()
    bst.delete_value(46)
    bst.print_values()
    bst.delete_value(48)
    bst.print_values()
    bst.delete_value(42)
    bst.print_values()
    bst.delete_value(43)
    bst.print_values()
    bst.delete_value(44)
    bst.print_values()
    



if __name__=="__main__":
    main()