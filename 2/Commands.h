//
// Created by Дарья on 06.01.2022.
//

#ifndef CPP_LABS_COMMANDS_H
#define CPP_LABS_COMMANDS_H

#include "Commands.h"
#include "Operations.h"
#include <istream>
#include <stack>
#include <memory>
#include <map>

class StackCalc {
    Memory memory;
public:
    void command(std::unique_ptr<Operation> cmd);

    static Operation *read_command(std::string &command_line);

    std::map<std::string, SafeInt<int64_t>> FindResult() {
        return memory.variables;
    }
};

StackCalc ReadLine();

StackCalc ReadFromFile(std::istream &file);

bool is_number(const std::string &s);

#endif //CPP_LABS_COMMANDS_H
