#include <iostream>

#include "custom.h"
#include "node.h"
#include "bst.h"

int main() {
    Node<std::string> x("xyz");
    CustomObj obj1{"name1"};

    auto tree1 = BST<double>(1.2f);
    auto tree2 = BST<std::string>(x);
    auto tree3 = BST<CustomObj>(obj1);
    tree1.print_root_val();
    tree2.print_root_val();
    tree3.print_root_val();

    return 0;
}
