template<typename T>
struct Node {
    T value;
    Node<T> *left;
    Node<T> *right;

    Node<T>() = delete;
    Node<T>(T val) {
        value = val;
        left = right = nullptr;
    };
    Node<T>(T val, Node<T>* l, Node<T>* r) {
        value = val; left = l; right = r;
    };

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

