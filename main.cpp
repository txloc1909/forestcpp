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

    void print_out() {
        std::cout << value << DELIM;
        if (left) {
            std::cout << left->value << DELIM;
        }
        if (right) {
            std::cout << right->value << DELIM;
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

    CustomObj obj1{"name1"};
    CustomObj obj2{20, "name2"};
    CustomObj obj3{30};
    std::cout << obj1 << "\n";
    std::cout << obj2 << "\n";
    std::cout << obj3 << "\n";

    return 0;
}
