#include <iostream>

#include "custom.h"

CustomObj::CustomObj(const CustomObj& other) {
    id = other.id;
    name = other.name;
}

CustomObj& CustomObj::operator=(const CustomObj &other) {
    this->id = other.id;
    this->name = other.name;
    return *this;
}

bool CustomObj::operator==(const CustomObj &other) {
    return (id == other.id) && (name == other.name);
}

std::ostream& operator<<(std::ostream& os, const CustomObj& obj) {
    os << obj.id << " | " << obj.name;
    return os;
}
