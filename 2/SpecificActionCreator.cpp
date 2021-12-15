//
// Created by Mikhail Okan on 15.11.2021.
//

#include "SpecificActionCreator.h"

std::map<std::string, std::function<StackActions::Action*(std::string)>> actions = {
        {"PUSH", [](std::string s){ return new StackActions::Push(s); }},
        {"POP", [](std::string s){ return new StackActions::Pop(s); }},
        {"PEEK", [](std::string s){ return new StackActions::Peek(s); }},
        {"PRINT", [](std::string s){ return new StackActions::Print(s); }},
        {"READ", [](std::string s){ return new StackActions::Read(s); }},
        {"ABS", [](std::string s){ return new StackActions::Abs(s); }},
        {"PLUS", [](std::string s){ return new StackActions::Plus(s); }},
        {"MINUS", [](std::string s){ return new StackActions::Minus(s); }},
        {"MUL", [](std::string s){ return new StackActions::Mul(s); }},
        {"DIV", [](std::string s){ return new StackActions::Div(s); }}
};

StackActions::Action *SAC::SpecificActionCreator::getAction(std::istringstream &line) {
    std::string action;
    line >> action;
    std::string args = line.str();
    if (action[0] != '#') {
        if (actions.count(action) == 0) {
            throw StackExceptions::InvalidOperation();
        }
        return actions[action](args);
    }
    return nullptr;
}