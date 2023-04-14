#include <ios>
#include <iostream>

template<typename T>
struct Node {
    T value;
    Node<T> *left;
    Node<T> *right;

    Node<T>() = delete;
    Node<T>(T val) {
        value = val;
        left = right = nullptr;
    }
    Node<T>(T val, Node<T>* l, Node<T>* r) {
        value = val; left = l; right = r;
    }

    void print_out() {
        std::cout << value << ";";
        if (left) {
            std::cout << left->value << ";";
        }
        if (right) {
            std::cout << right->value << ";";
        }
        std::cout << "\n";
    };
};

int main() {
    Node<double> a(1.2f);
    Node<double> b(1.0f);
    Node<double> c(2.0f, &a, &b);
    a.print_out();
    b.print_out();
    c.print_out();

    Node<std::string> x("xyz");
    Node<std::string> y("abc");
    Node<std::string> z("def", &x, &y);
    x.print_out();
    y.print_out();
    z.print_out();
    return 0;
}
