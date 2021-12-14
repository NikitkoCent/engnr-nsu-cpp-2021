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
    stack<SafeInt<int64_t>> _stack;
    map<string, SafeInt<int64_t>> m;
public:
    void exec(std::unique_ptr<Command> cmd) {
        cmd->exec(_stack, m);
    }

    void parse_stream(std::istream &in){
        string line;
        while (!in.eof()) {
//            cin >> line;
            getline(in, line);

            cout << "Read line: \""<< line << "\"" << in.eof() << endl;

            if (line.empty()) continue; // don't parse empty line

            stringstream ls(line);
            std::unique_ptr<Command> shit(CommandFactory::parseCmd(ls));
            if (shit != nullptr)
                this->exec(std::move(shit));
        }
    }

    map<string, SafeInt<int64_t>> getM() { return m; }
};

#endif //CPP_LABS_STACKCALCULATOR_H
