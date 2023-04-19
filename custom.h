#pragma once

#include <iostream>
#include <ostream>
#include <string>

struct CustomObj {
    int id;
    std::string name;

    CustomObj(int id_, const std::string &name_): id(id_), name(name_) {};
    CustomObj() : CustomObj(0, "") {};
    CustomObj(int id_) : CustomObj(id_, "") {};
    CustomObj(std::string& name) : CustomObj(0, name) {};
    CustomObj(const std::string&& name) : CustomObj(0, name) {};

    CustomObj(const CustomObj& other);
    CustomObj& operator=(const CustomObj& other);

    bool operator==(const CustomObj& other);
};

std::ostream& operator<<(std::ostream& os, const CustomObj& obj);

