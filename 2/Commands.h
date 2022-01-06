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

struct ContextExecution {
    std::stack<SafeInt<int64_t, CustomException>> stack;
    std::max<std::string, SafeInt<int64_t, CustomException>> variables;
};


class Command {
public:
    explicit Command(std::string &args) { params = args; }

    virtual void
    command(ContextExecution &context_execution) = 0;

    virtual ~Command() = default ;

protected:
    std::string params;
};

class StackCalc {
    ContextExecution context_execution;
public:
    void command(std::unique_ptr<Command> cmd);

    Command *read_command(std::string &command_line);

    std::map<std::string, SafeInt<int64_t, CustomException>> FindResult() {
        return context_execution.variables;
    }
};
StackCalc ReadLine();
StackCalc ReadFromFile(std::istream &file);

#endif //CPP_LABS_COMMANDS_H
