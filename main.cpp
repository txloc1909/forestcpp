#include <iostream>

const std::string DELIM = " | ";

struct CustomObj {
    int id;
    std::string name;

    CustomObj() = default;
    CustomObj(int id_, const std::string &name_): id(id_), name(name_) {};
    CustomObj(int id_) : CustomObj(id_, "") {};
    CustomObj(std::string& name) : CustomObj(0, name) {};
    CustomObj(const std::string&& name) : CustomObj(0, name) {};
};

std::ostream& operator<<(std::ostream& os, const CustomObj& obj) {
    os << obj.id << DELIM << obj.name;
    return os;
}

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

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    os << node.value << DELIM;
    if (node.left) {
        os << node.left->value;
    }
    os << DELIM;
    if (node.right) {
        os << node.right->value;
    }
    os << DELIM;
    return os;
}


int main() {
    Node<double> a(1.2f);
    Node<double> b(1.0f);
    Node<double> c(2.0f, &a, &b);
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";

    Node<std::string> x("xyz");
    Node<std::string> y("abc");
    Node<std::string> z("def", &x, &y);
    std::cout << x << "\n";
    std::cout << y << "\n";
    std::cout << z << "\n";

    CustomObj obj1{"name1"};
    CustomObj obj2{20, "name2"};
    CustomObj obj3{30};
    std::cout << obj1 << "\n";
    std::cout << obj2 << "\n";
    std::cout << obj3 << "\n";

    return 0;
}
