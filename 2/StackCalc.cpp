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
    std::unique_ptr<SAC::SpecificActionCreator> fabric = std::make_unique<SAC::SpecificActionCreator>();
    while (!input.eof()) {
        std::getline(input, line);
        std::istringstream action_line(line);
        action = fabric->getAction(action_line);
        if (action != nullptr) {
            this->act(std::move(action));
        }
    }
}