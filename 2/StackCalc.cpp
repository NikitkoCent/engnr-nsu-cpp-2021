//
// Created by Mikhail Okan on 15.11.2021.
//

#include "StackCalc.h"

void SC::StackCalc::act(std::unique_ptr<StackActions::Action> action) {
    action->act(context);
}

void SC::StackCalc::execute(std::istream &input) {
    std::string line;
    std::unique_ptr<StackActions::Action> action;
    while (!input.eof()) {
        std::getline(input, line);
        std::istringstream action_line(line);
//        std::stringstream action_line(line);
        action = std::unique_ptr<StackActions::Action>(SAC::SpecificActionCreator::getAction(action_line));
        if (action != nullptr) {
            this->act(std::move(action));
        }
    }
}

SafeInt<long> SC::StackCalc::get_last() {
    return context.vars["0x0badc0de"];
}