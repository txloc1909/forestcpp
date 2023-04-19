#pragma once

#include <iostream>

#include "node.h"

template<typename T>
class BST {
    /*
     * Binary Search Tree
     */

    private:
        Node<T> root;

    public:
        BST(T root_val) {
            this->root = Node<T>(root_val);
        };

        BST(Node<T>& root_node) {
            this->root = std::move(root_node);
        }

        void insert(T new_val);
        void insert(Node<T> new_node);

        void print_root_val() {
            std::cout << (*this).root.value << "\n";
        }
};

