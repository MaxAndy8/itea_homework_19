#include <iostream>
#include "MyBinaryTree.h"

int main() {

    MY::BinaryTree<int> tree;
    tree.insert(3);
    tree.insert(5);
    tree.insert(2);

    std::cout << tree;  // ������ ����� � ������� inorder
    return 0;
}