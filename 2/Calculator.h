#pragma once

#include "lib/SafeInt/SafeInt.hpp"

#include <stack>
#include <sstream>
#include <map>
#include <iostream>
#include <cstdint>

namespace ns_calculator {

    class Calculator {

    private:

        std::stack<SafeInt<int64_t>> values;
        std::map<std::string, SafeInt<int64_t>> names_and_values;

    public:
        void plus();

        void minus();

        void div();

        void mul();

        void push(SafeInt<int64_t> value);

        void peek(const std::string &varname);

        SafeInt<int64_t> print() const;

        static SafeInt<int64_t> abs(SafeInt<int64_t> value);

        void pop();

        std::istream &read(std::istream &is);

        void push(const std::string &varname);

        SafeInt<int64_t> pop_elem();
    };
}
