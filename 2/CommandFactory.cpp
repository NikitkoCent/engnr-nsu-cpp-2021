//
// Created by gav on 10/12/2021.
//

#include "CommandFactory.h"

Command* CommandFactory::parseCmd(stringstream &cmd){
    string cmd_name;
    cmd >> cmd_name;
    string ass = cmd.str();

    if (cmd_name[0] == '#')
        return nullptr;

    if (cmd_name == "PUSH") {
        return new Push(ass);
    } else if (cmd_name == "PEEK"){
        return new Peek(ass);
    } else if (cmd_name == "ABS"){
        return new Abs(ass);
    } else if (cmd_name == "PLUS"){
        return new Plus(ass);
    } else if (cmd_name == "MINUS"){
        return new Minus(ass);
    } else if (cmd_name == "DIV"){
        return new Div(ass);
    } else if (cmd_name == "MUL"){
        return new Mul(ass);
    } else if (cmd_name == "PRINT"){
        return new Print(ass);
    } else if (cmd_name == "READ"){
        return new Read(ass);
    } else if (cmd_name == "POP"){
        return new Pop(ass);
    } else {
        throw std::runtime_error("Invalid command!");
    }
}
