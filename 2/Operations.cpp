//
// Created by Дарья on 06.01.2022.
//
#include "Commands.h"

#include <string>
#include <iostream>
#include <charconv>

void Pop::command(Memory &memory) {
    if (!memory.stack.empty()) {
        memory.stack.pop();
    } else {
        throw EmptyStack();
    }
}

void Push::command(Memory &memory) {
    if (is_number(params)) {
        int64_t result{};
        auto[ptr, ec]{std::from_chars(params.data(), params.data() + params.size(), result)};
        if (ec == std::errc::result_out_of_range) {
            throw OverflowException();
        }
        memory.stack.push(result);
    } else {
        auto elem = memory.variables.find(params);
        if (elem == memory.variables.end()) {
            throw WrongArgument();
        } else memory.stack.push(elem->second);
    }
}

void Peek::command(Memory &memory) {
    if (!memory.stack.empty()) {
        memory.variables[params] = memory.stack.top();
    } else {
        throw EmptyStack();
    }
}

void Abs::command(Memory &memory) {
    if (!memory.stack.empty()) {
        SafeInt<int64_t, CustomException> val = memory.stack.top();
        memory.stack.pop();
        if (val < 0) {
            SafeInt<int64_t, CustomException> result = -val;
            memory.stack.push(result);
        } else {
            SafeInt<int64_t, CustomException> result = val;
            memory.stack.push(result);
        }
    } else {
        throw EmptyStack();
    }
}

void Plus::command(Memory &memory) {
    if (memory.stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = memory.stack.top();
        memory.stack.pop();
        SafeInt<int64_t, CustomException> val2 = memory.stack.top();
        memory.stack.pop();
        SafeInt<int64_t, CustomException> result = val1 + val2;
        memory.stack.push(result);
    } else {
        throw EmptyStack();
    }
}

void Minus::command(Memory &memory) {
    if (memory.stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = memory.stack.top();
        memory.stack.pop();
        SafeInt<int64_t, CustomException> val2 = memory.stack.top();
        memory.stack.pop();
        SafeInt<int64_t, CustomException> result = val2 - val1;
        memory.stack.push(result);
    } else {
        throw EmptyStack();
    }
}

void Multiply::command(Memory &memory) {
    if (memory.stack.size() >= 2) {
        SafeInt<int64_t, CustomException> val1 = memory.stack.top();
        memory.stack.pop();
        SafeInt<int64_t, CustomException> val2 = memory.stack.top();
        memory.stack.pop();
        SafeInt<int64_t, CustomException> result = val1 * val2;
        memory.stack.push(result);
    } else {
        throw EmptyStack();
    }
}

void Division::command(Memory &memory) {
    if (memory.stack.size() >= 2) {
        int64_t val1 = memory.stack.top();
        memory.stack.pop();
        int64_t val2 = memory.stack.top();
        if (val1 != 0) {
            memory.stack.pop();
            int64_t res;
            SafeDivide(val2, val1, res);
            memory.stack.push(res);
        } else {
            throw DivisionByZero();
        }
    } else {
        throw EmptyStack();

    }
}

void Print::command(Memory &memory) {
    if (!memory.stack.empty()) {
        SafeInt<int64_t, CustomException> val = memory.stack.top();
        memory.variables["result"] = val;
        std::cout << (int64_t) val << std::endl;
    } else {
        throw EmptyStack();
    }
}

void Read::command(Memory &memory) {
    std::string val;
    std::cin >> val;
    if (is_number(val)) {
        int64_t result{};
        std::from_chars(val.data(), val.data() + val.size(), result);
        memory.stack.push(result);
    } else {
        throw EmptyStack();
    }
}

void Comment::command(Memory &memory) {}
