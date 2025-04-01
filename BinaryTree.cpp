#include "BinaryTree.h"

#include <iostream>

BinaryTree::inOrderIterator::inOrderIterator(Node *current) {
    while (current != nullptr) {
        nodes.push(current);
        current = current->left;
    }
}

bool BinaryTree::inOrderIterator::operator==(const inOrderIterator &other) const {
    return nodes.empty();
}

bool BinaryTree::inOrderIterator::operator!=(const inOrderIterator &other) const {
    return !nodes.empty();
}

int BinaryTree::inOrderIterator::operator*() const {
    return nodes.top()->value;
}

BinaryTree::inOrderIterator &BinaryTree::inOrderIterator::operator++() {
    if (nodes.empty()) return *this;

    auto top = nodes.top();
    nodes.pop();
    Node *temp = top->right;

    while (temp != nullptr) {
        nodes.push(temp);
        temp = temp->left;
    }

    return *this;
}

BinaryTree::Node *BinaryTree::copyTree(const Node *root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node *newNode = new Node{root->value};
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

void BinaryTree::clear(Node *root) {
    if (root == nullptr) {
        return;
    }

    clear(root->left);
    clear(root->right);

    delete root;
}

void BinaryTree::inorderTraversalPrintRecursive(const Node *root) const {
    if (root == nullptr) {
        return;
    }

    inorderTraversalPrintRecursive(root->left);
    std::cout << root->value << std::endl;
    inorderTraversalPrintRecursive(root->right);
}

void BinaryTree::preorderTraversalPrintRecursive(const Node *root) const {
    if (root == nullptr) {
        return;
    }

    std::cout << root->value << std::endl;
    preorderTraversalPrintRecursive(root->left);
    preorderTraversalPrintRecursive(root->right);
}

void BinaryTree::postorderTraversalPrintRecursive(const Node *root) const {
    if (root == nullptr) {
        return;
    }

    postorderTraversalPrintRecursive(root->left);
    postorderTraversalPrintRecursive(root->right);
    std::cout << root->value << std::endl;
}

//      10
//     /  \
//    5    15
//   / \   /  \
//  3   7 12  18
BinaryTree::BinaryTree() {
    root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
}

BinaryTree::BinaryTree(Node *root) {
    this->root = copyTree(root);
}

BinaryTree::~BinaryTree() {
    clear(root);
}

void BinaryTree::inorderTraversalPrint() const {
    inorderTraversalPrintRecursive(root);
}

void BinaryTree::preorderTraversalPrint() const {
    preorderTraversalPrintRecursive(root);
}

void BinaryTree::postorderTraversalPrint() const {
    postorderTraversalPrintRecursive(root);
}

BinaryTree::inOrderIterator BinaryTree::begin() {
    inOrderIterator beginIterator(root);
    return beginIterator;
}

BinaryTree::inOrderIterator BinaryTree::end() {
    inOrderIterator endIterator;
    return endIterator;
}

bool isBST(BinaryTree &tree) {
    int prevValue = *tree.begin();
    for (auto it = ++tree.begin(); it != tree.end(); ++it) {
        if (prevValue >= *it) {
            return false;
        }
        prevValue = *it;
    }

    return true;
}
