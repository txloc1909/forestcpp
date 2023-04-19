#pragma once

#include <ostream>

template<typename T>
struct Node {
    T value;
    Node<T> *left;
    Node<T> *right;

    Node<T>() {
        value = T();
        left = right = nullptr;
    };
    Node<T>(T val) {
        value = val;
        left = right = nullptr;
    };

    Node<T>(const Node<T>& other) {
        value = other.value;
        left = other.left;
        right = other.right;
    };
    Node<T>& operator=(const Node<T>& other) {
        this->value = other.value;
        this->left = other.left;
        this->right = other.right;
        return *this;
    }

    Node<T>(T val, Node<T>* l, Node<T>* r) {
        value = val; left = l; right = r;
    };

    bool operator==(const Node<T>& other) {
        return (value == other.value) && (left == other.left) && (right == other.right);
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    os << node.value << " | ";
    if (node.left) {
        os << node.left->value;
    }
    os << " | ";
    if (node.right) {
        os << node.right->value;
    }
    os << " | ";
    return os;
}

