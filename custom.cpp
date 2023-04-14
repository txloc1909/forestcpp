#include <iostream>

#include "custom.h"

std::ostream& operator<<(std::ostream& os, const CustomObj& obj) {
    os << obj.id << " | " << obj.name;
    return os;
}
