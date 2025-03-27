#include <iostream>
#include "BinaryTree.h"


//      10
//     /  \
//    5    15
//   / \   /  \
//  3   7 12  18

int main() {
    BinaryTree *bintree = new BinaryTree();

    for (auto it = bintree->begin(); it != bintree->end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    bintree->inorderTraversalPrint();

    delete bintree;
    return 0;
}

