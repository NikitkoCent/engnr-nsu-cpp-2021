#pragma once

#include "Calculator.h"
#include "lib/SafeInt/SafeInt.hpp"

#include <cstdint>
#include <iostream>
#include <vector>
#include <sstream>

bool is_number(const std::string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

SafeInt<int64_t> get_result(const std::string &str) {
    ns_calculator::Calculator c;
    std::stringstream iss(str);
    std::string command;
    try {
        while (iss >> command) {
            if (command == "#") {
                std::string comment;
                std::getline(iss, comment, '\n');
                std::cout << comment << std::endl;
            } else if (command == "POP") {
                c.pop();
            } else if (command == "PEEK") {
                std::string varname;
                iss >> varname;
                c.peek(varname);
            } else if (command == "PUSH") {
                std::string varname;
                iss >> varname;
                if (is_number(varname)) {
                    c.push(stoi(varname));
                } else {
                    c.push(varname);
                }
            } else if (command == "ABS") {
                SafeInt<int64_t> value = c.pop_elem();
                c.push(c.abs(value));
            } else if (command == "MINUS") {
                c.minus();
            } else if (command == "PLUS") {
                c.plus();
            } else if (command == "MUL") {
                c.mul();
            } else if (command == "DIV") {
                c.div();
            } else if (command == "PRINT") {
                return c.print();
            } else if (command == "READ") {
                int value;
                iss >> value;
                c.push(value);
            }
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
