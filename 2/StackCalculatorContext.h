//
// Created by gav on 22/12/2021.
//

#ifndef CPP_LABS_STACKCALCULATORCONTEXT_H
#define CPP_LABS_STACKCALCULATORCONTEXT_H

#include <stack>
#include <map>
#include <string>

class StackCalculatorContext {
    std::stack<SafeInt<int64_t>> stack{};
    std::map<std::string, SafeInt<int64_t>> m{};

public:
    auto& get_stack(){
        return stack;
    }

    auto& get_map(){
        return m;
    }
};

#endif //CPP_LABS_STACKCALCULATORCONTEXT_H
