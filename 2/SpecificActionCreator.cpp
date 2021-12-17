//
// Created by Mikhail Okan on 15.11.2021.
//

#include "SpecificActionCreator.h"

std::unique_ptr<StackActions::Action> SAC::SpecificActionCreator::getAction(std::istringstream &line) {
    std::string action;
    line >> action;
    std::string args = line.str();
    if ((action[0] != '#') && (action.length())) {
        return std::unique_ptr<StackActions::Action>(findAction(action)(args));
    }
    return nullptr;
}

std::function<StackActions::Action *(std::string)> SAC::SpecificActionCreator::findAction(const std::string& action) {
    if (actions.count(action) == 0) {
        throw StackExceptions::InvalidOperation();
    }
    return actions[action];
}
