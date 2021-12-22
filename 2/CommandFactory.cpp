//
// Created by gav on 10/12/2021.
//

#include "CommandFactory.h"

std::unique_ptr<Command> CommandFactory::parseCmd(stringstream &cmd){
    string cmd_name;
    cmd >> cmd_name;
    string ass = cmd.str();

    if (cmd_name[0] == '#')
        return nullptr;

    if (cmd_name == "PUSH") {
        return std::unique_ptr<Command>(new Push(ass));
    } else if (cmd_name == "PEEK"){
        return std::unique_ptr<Command>(new Peek(ass));
    } else if (cmd_name == "ABS"){
        return std::unique_ptr<Command>(new Abs(ass));
    } else if (cmd_name == "PLUS"){
        return std::unique_ptr<Command>(new Plus(ass));
    } else if (cmd_name == "MINUS"){
        return std::unique_ptr<Command>(new Minus(ass));
    } else if (cmd_name == "DIV"){
        return std::unique_ptr<Command>(new Div(ass));
    } else if (cmd_name == "MUL"){
        return std::unique_ptr<Command>(new Mul(ass));
    } else if (cmd_name == "PRINT"){
        return std::unique_ptr<Command>(new Print(ass));
    } else if (cmd_name == "READ"){
        return std::unique_ptr<Command>(new Read(ass));
    } else if (cmd_name == "POP"){
        return std::unique_ptr<Command>(new Pop(ass));
    } else {
        throw InvalidArgumentsException();
    }
}
