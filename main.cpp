#include <iostream>

#include "custom.h"
#include "node.h"

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
