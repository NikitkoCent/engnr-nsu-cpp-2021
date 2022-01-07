//
// Created by brucebek on 03.01.2022.
//

#include "Calculator.h"
#include "commands.h"
#include <sstream>
#include <memory>


void Calculator::perform(const std::string &raw_command)
{
    std::stringstream ss(raw_command);
    std::string command;
    std::string arg;
    ss >> command;
    ss >> arg;
    if (command.empty()) return;
    std::unique_ptr<Command> prepared_command(make_command(*this, command, arg));
    prepared_command -> run();
}