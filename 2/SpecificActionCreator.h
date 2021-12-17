//
// Created by Mikhail Okan on 15.11.2021.
//

#ifndef STACK_CALC_SPECIFICACTIONCREATOR_H
#define STACK_CALC_SPECIFICACTIONCREATOR_H
#include "Actions.h"
#include <functional>
namespace SAC {
    class SpecificActionCreator {
    private:
        std::function<StackActions::Action *(std::string)> findAction(const std::string& action);
        std::map<std::string, std::function<StackActions::Action *(std::string)>> actions;
    public:
        SpecificActionCreator() {
            actions = {
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
        }
        std::unique_ptr<StackActions::Action> getAction(std::istringstream &line);
    };
}


#endif //STACK_CALC_SPECIFICACTIONCREATOR_H
