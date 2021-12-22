//
// Created by gav on 08/10/2021.
//

#include "StackCalculator.hpp"

void StackCalculator::exec(std::unique_ptr<Command> cmd){
    cmd->exec(ctx);
}

void StackCalculator::parse_stream(std::istream &in) {
    string line;
    while (!in.eof() && !in.bad() && !in.fail()) {
        getline(in, line);

        if (line.empty()) continue; // don't parse empty line

        stringstream ls(line);
        std::unique_ptr<Command> tmp = CommandFactory::parseCmd(ls);
        if (tmp != nullptr)
            this->exec(std::move(tmp));
    }
}

StackCalculatorContext& StackCalculator::get_ctx() {
    return ctx;
}
