// BOJ-01991 / 트리 순회
// devgeon, 2024.01.01, C++17
// https://www.acmicpc.net/problem/1991

#include <iostream>

using namespace std;

class Node {
  private:
    char data_ = '\0';
    Node *parent_ = nullptr;
    Node *left_ = nullptr;
    Node *right_ = nullptr;

  public:
    Node(char data, Node *parent = nullptr);
    ~Node();
    char getData() { return data_; }
    Node *getParent() { return parent_; }
    Node *getLeft() { return left_; }
    Node *getRight() { return right_; }
    void setParent(Node *node) { parent_ = node; }
    void setLeft(Node *node) { left_ = node; }
    void setRight(Node *node) { right_ = node; }
};

class BinaryTree {
  private:
    Node *root_ = nullptr;
    Node *findNode(char data, Node *root);

  public:
    BinaryTree(char root) { root_ = new Node(root); }
    ~BinaryTree() { removeSubTree(root_); }
    void appendChild(char parent, char left = '\0', char right = '\0');
    void removeSubTree(char data);
    void removeSubTree(Node *target);
    void preorderTraversal(Node *root = nullptr);
    void inorderTraversal(Node *root = nullptr);
    void postorderTraversal(Node *root = nullptr);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_nodes = 0;
    cin >> total_nodes;
    BinaryTree bin_tree = BinaryTree('A');
    char parent = '\0', left = '\0', right = '\0';

    while (total_nodes) {
        cin.get();
        parent = cin.get();
        cin.get();
        left = cin.get();
        cin.get();
        right = cin.get();

        bin_tree.appendChild(parent, (left != '.' ? left : '\0'),
                             (right != '.' ? right : '\0'));
        total_nodes--;
    }

    bin_tree.preorderTraversal();
    cout << "\n";
    bin_tree.inorderTraversal();
    cout << "\n";
    bin_tree.postorderTraversal();
    cout << "\n";

    return 0;
}

Node::Node(char data, Node *parent) {
    data_ = data;
    if (parent != nullptr) {
        parent_ = parent;
    }
}

Node::~Node() {
    if (parent_ == nullptr) {
        return;
    }
    if (parent_->left_ == this) {
        parent_->left_ = nullptr;
    } else {
        parent_->right_ = nullptr;
    }
}

Node *BinaryTree::findNode(char data, Node *root) {
    Node *result = nullptr;
    if (root->getData() == data) {
        return root;
    }
    if (root->getLeft() != nullptr) {
        result = findNode(data, root->getLeft());
        if (result != nullptr) {
            return result;
        }
    }
    if (root->getRight() != nullptr) {
        result = findNode(data, root->getRight());
        if (result != nullptr) {
            return result;
        }
    }
    return nullptr;
}

void BinaryTree::appendChild(char parent, char left, char right) {
    Node *parent_node = findNode(parent, root_);
    if (parent_node == nullptr) {
        throw runtime_error("No matching nodes found.");
    }
    if (left != '\0') {
        if (parent_node->getLeft() != nullptr) {
            throw runtime_error("Left child already exists.");
        }
        parent_node->setLeft(new Node(left, parent_node));
    }
    if (right != '\0') {
        if (parent_node->getRight() != nullptr) {
            throw runtime_error("Right child already exists.");
        }
        parent_node->setRight(new Node(right, parent_node));
    }
}

void BinaryTree::removeSubTree(char root) {
    Node *target = findNode(root, root_);
    if (target == nullptr) {
        throw runtime_error("No matching nodes found.");
    }
    removeSubTree(target);
}

void BinaryTree::removeSubTree(Node *target) {
    if (target->getLeft() != nullptr) {
        removeSubTree(target->getLeft());
    }
    if (target->getLeft() != nullptr) {
        removeSubTree(target->getLeft());
    }
    delete target;
}

void BinaryTree::preorderTraversal(Node *root) {
    if (root == nullptr) {
        root = root_;
    }
    cout << root->getData();
    if (root->getLeft() != nullptr) {
        preorderTraversal(root->getLeft());
    }
    if (root->getRight() != nullptr) {
        preorderTraversal(root->getRight());
    }
}

void BinaryTree::inorderTraversal(Node *root) {
    if (root == nullptr) {
        root = root_;
    }
    if (root->getLeft() != nullptr) {
        inorderTraversal(root->getLeft());
    }
    cout << root->getData();
    if (root->getRight() != nullptr) {
        inorderTraversal(root->getRight());
    }
}

void BinaryTree::postorderTraversal(Node *root) {
    if (root == nullptr) {
        root = root_;
    }
    if (root->getLeft() != nullptr) {
        postorderTraversal(root->getLeft());
    }
    if (root->getRight() != nullptr) {
        postorderTraversal(root->getRight());
    }
    cout << root->getData();
}
