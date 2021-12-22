//
// Created by gav on 08/10/2021.
//

#ifndef CPP_LABS_STACKCALCULATOR_H
#define CPP_LABS_STACKCALCULATOR_H

#include <stack>
#include <vector>
#include <memory>
#include <map>

#include "lib/SafeInt/SafeInt.hpp"

#include "Commands.h"
#include "CommandFactory.h"

using std::stack;
using std::string;
using std::vector;
using std::map;

class StackCalculator {
    StackCalculatorContext ctx;

public:
    void exec(std::unique_ptr<Command> cmd);
    void parse_stream(std::istream &in);
    StackCalculatorContext& get_ctx();
};

#endif //CPP_LABS_STACKCALCULATOR_H
