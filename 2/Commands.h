//
// Created by gav on 08/10/2021.
//

#ifndef CPP_LABS_COMMANDS_H
#define CPP_LABS_COMMANDS_H

#include <map>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

#include "SafeInt.hpp"
#include "Exceptions.h"
#include "StackCalculatorContext.h"

using std::map;
using std::stringstream;
using std::string;
using std::stack;
using std::cout;
using std::cin;
using std::endl;

class Command {
protected:
    stringstream args;
public:
    explicit Command(string &_args) {
        string ass;
        args = stringstream(_args);
        args >> ass; // read cmd name
    }

    virtual void exec(StackCalculatorContext &ctx) = 0;

    virtual ~Command() {};
};

class Push : public Command {
public:
    explicit Push(string &_args) : Command(_args) {}

    static bool is_number(const std::string &line);

    void exec(StackCalculatorContext &ctx) override;
};

class Pop : public Command {
public:
    explicit Pop(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};

class Peek : public Command {
public:
    explicit Peek(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};

class Abs : public Command {
public:
    explicit Abs(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};

class Plus : public Command {
public:
    explicit Plus(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};

class Minus : public Command {
public:
    explicit Minus(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};

class Mul : public Command {
public:
    explicit Mul(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};

class Div : public Command {
public:
    explicit Div(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};

class Print : public Command {
public:
    explicit Print(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};

class Read : public Command {
public:
    explicit Read(string &_args) : Command(_args) {}

    void exec(StackCalculatorContext &ctx) override;
};



#endif //CPP_LABS_COMMANDS_H
