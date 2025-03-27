#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stack>


class BinaryTree {
private:
    struct Node {
        int value;
        Node *left = nullptr;
        Node *right = nullptr;
    };

    Node *root;

private:
    class inOrderIterator {
    private:
        std::stack<Node *> nodes;

    public:
        inOrderIterator() = default;

        explicit inOrderIterator(Node *current);

        bool operator==(const inOrderIterator &other) const;

        bool operator!=(const inOrderIterator &other) const;

        int operator*() const;

        inOrderIterator &operator++();
    };

private:
    Node *copyTree(const Node *root);

    void clear(Node *root);

    void inorderTraversalPrintRecursive(const Node *root) const;

    void preorderTraversalPrintRecursive(const Node *root) const;

    void postorderTraversalPrintRecursive(const Node *root) const;

public:
    explicit BinaryTree();

    explicit BinaryTree(Node *root);

    ~BinaryTree();

    void inorderTraversalPrint() const;

    void preorderTraversalPrint() const;

    void postorderTraversalPrint() const;

    inOrderIterator begin();

    inOrderIterator end();
};


#endif //BINARYTREE_H
