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

SafeInt<int64_t> get_result() {
    ns_calculator::Calculator c;
    std::string command;
    try {
        while (std::cin >> command) {
            if (command == "#") {
                std::string comment;
                std::getline(std::cin, comment, '\n');
                std::cout << comment << std::endl;
            } else if (command == "POP") {
                c.pop();
            } else if (command == "PEEK") {
                std::string varname;
                std::cin >> varname;
                c.peek(varname);
            } else if (command == "PUSH") {
                std::string varname;
                std::cin >> varname;
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
                SafeInt<int64_t> res = c.print();
                return res;
            } else if (command == "READ") {
                int value;
                std::cin >> value;
                c.push(value);
            }
        }
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}
